// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SIMPLESLATEPLUGIN_API SSimpleSlatePluginMenu : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSimpleSlatePluginMenu)
	{}
	SLATE_END_ARGS()

	FReply OnTestButtonClicked();
	void OnTestCheckboxStateChanged(ECheckBoxState NewState);
	ECheckBoxState IsTestBoxChecked() const;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

protected:
	bool bIsTestBoxChecked;
};
