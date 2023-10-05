// SimpleSlatePluginCommands.h

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "SimpleSlatePluginStyle.h"

class FSimpleSlatePluginCommands : public TCommands<FSimpleSlatePluginCommands>
{
public:

	FSimpleSlatePluginCommands()
		: TCommands<FSimpleSlatePluginCommands>(TEXT("SimpleSlatePlugin"), NSLOCTEXT("Contexts", "SimpleSlatePlugin", "SimpleSlatePlugin Plugin"), NAME_None, FSimpleSlatePluginStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};