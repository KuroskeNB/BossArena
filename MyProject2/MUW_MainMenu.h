// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MUW_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UMUW_MainMenu : public UUserWidget
{
	GENERATED_BODY()
	public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*StartGame;
	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*ExitGame;

	private:

	UFUNCTION()
	void OnStartGameClicked();
	UFUNCTION()
	void OnExitGameClicked();
};
