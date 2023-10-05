// SSimpleSlatePluginMenu.cpp

#include "SSimpleSlatePluginMenu.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSimpleSlatePluginMenu::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.Text(FText::FromString("Test Button"))
			]
			+SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			.AutoWidth()
			[
				SNew(SButton)
				.Text(FText::FromString("Get Checkbox State"))
				.OnClicked(this, &SSimpleSlatePluginMenu::OnTestButtonClicked)
			]
		]
		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			.AutoWidth()
			[
				SNew(STextBlock)
				.MinDesiredWidth(100)
				.Text(FText::FromString("Test Checkbox"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(SCheckBox)
				.OnCheckStateChanged(this, &SSimpleSlatePluginMenu::OnTestCheckboxStateChanged)
				.IsChecked(this, &SSimpleSlatePluginMenu::IsTestBoxChecked)
			]
		]
	];
}

void SSimpleSlatePluginMenu::OnTestCheckboxStateChanged(ECheckBoxState NewState)
{
	bIsTestBoxChecked = 
		NewState == ECheckBoxState::Checked ? 
		true : 
		false;
}

ECheckBoxState SSimpleSlatePluginMenu::IsTestBoxChecked() const
{
	return bIsTestBoxChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

FReply SSimpleSlatePluginMenu::OnTestButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("The checkbox is %s."), (bIsTestBoxChecked ? TEXT("checked") : TEXT("unchecked")));
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION