// SimpleSlatePlugin.cpp

#include "SimpleSlatePlugin.h"
#include "SimpleSlatePluginStyle.h"
#include "SimpleSlatePluginCommands.h"
#include "SSimpleSlatePluginMenu.h"

#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName SimpleSlatePluginTabName("SimpleSlatePlugin");

#define LOCTEXT_NAMESPACE "FSimpleSlatePluginModule"

void FSimpleSlatePluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FSimpleSlatePluginStyle::Initialize();
	FSimpleSlatePluginStyle::ReloadTextures();

	FSimpleSlatePluginCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FSimpleSlatePluginCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FSimpleSlatePluginModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FSimpleSlatePluginModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(SimpleSlatePluginTabName, FOnSpawnTab::CreateRaw(this, &FSimpleSlatePluginModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FSimpleSlatePluginTabTitle", "Tab title goes here"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FSimpleSlatePluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FSimpleSlatePluginStyle::Shutdown();

	FSimpleSlatePluginCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(SimpleSlatePluginTabName);
}

TSharedRef<SDockTab> FSimpleSlatePluginModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FSimpleSlatePluginModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("SimpleSlatePlugin.cpp"))
		);
	SNew(STextBlock);
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			[
				SNew(SSimpleSlatePluginMenu)
			]
			//[
			//	SNew(STextBlock)
			//	.Text(WidgetText)
			//]
		];
}

void FSimpleSlatePluginModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(SimpleSlatePluginTabName);
}

void FSimpleSlatePluginModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FSimpleSlatePluginCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FSimpleSlatePluginCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSimpleSlatePluginModule, SimpleSlatePlugin)