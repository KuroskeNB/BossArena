// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_GameEnd.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UUW_GameEnd : public UUserWidget
{
	GENERATED_BODY()
	public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*SwitchWeapon;
	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*RestartGame;
	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*ChangeDiff;

	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*SwordWeapon;
	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*BowWeapon;

	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*EasyDiff;
	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*HardDiff;

	UPROPERTY(meta = (BindWidgetOptional))
	class UTextBlock* WinText;
	UPROPERTY(meta = (BindWidgetOptional))
	class UTextBlock* FailText;
    
	private:

	UFUNCTION()
	void OnSwitchWeaponClicked();
	UFUNCTION()
	void OnRestartGameClicked();

	UFUNCTION()
	void OnSwordWeaponClicked();
	UFUNCTION()
	void OnBowWeaponClicked();

	UFUNCTION()
	void OnChangeDiffClicked();
	UFUNCTION()
	void OnEasyDiffClicked();
	UFUNCTION()
	void OnHardDiffClicked();
};
