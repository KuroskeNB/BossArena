// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MUW_WeaponChoose.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UMUW_WeaponChoose : public UUserWidget
{
	GENERATED_BODY()
	public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*ChooseSword;
	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*ChooseBow;

	private:

	UFUNCTION()
	void OnChooseSwordClicked();
	UFUNCTION()
	void OnChooseBowClicked();
};
