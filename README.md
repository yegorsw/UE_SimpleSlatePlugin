# UE_SimpleSlatePlugin
A simple example of an Unreal Engine plugin which creates a window using Slate.

This plugin was created based on the following official tutorial from Epic Games:
https://docs.unrealengine.com/5.0/en-US/slate-editor-window-quickstart-guide-for-unreal-engine/

However, their tutorial had a number of issues which have been fixed.. For example, their tutorial contained a namespace, FIsChecked , which does not exist.
Their code also used more complex arguments for the event callbacks like
.OnCheckStateChanged(FOnCheckStateChanged::CreateSP(this, &SSimpleSlatePluginMenu::OnTestCheckboxStateChanged))
which have been simplified:
.OnCheckStateChanged(this, &SSimpleSlatePluginMenu::OnTestCheckboxStateChanged)
