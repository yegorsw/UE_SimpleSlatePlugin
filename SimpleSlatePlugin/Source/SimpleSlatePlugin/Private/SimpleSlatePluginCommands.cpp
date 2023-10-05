// SimpleSlatePluginCommands.cpp

#include "SimpleSlatePluginCommands.h"

#define LOCTEXT_NAMESPACE "FSimpleSlatePluginModule"

void FSimpleSlatePluginCommands::RegisterCommands()
{
	// This is the name of the plugin, as it appears in the "Window" menu, and the hover text for it.
	UI_COMMAND(OpenPluginWindow, "Simple Slate Plugin", "Opens an example slate plugin.", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
