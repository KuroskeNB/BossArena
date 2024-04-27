// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MUW_DifficultChoose.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UMUW_DifficultChoose : public UUserWidget
{
	GENERATED_BODY()
	public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*EasyDiff;
	UPROPERTY(meta = (BindWidgetOptional))
	class UButton*HardDiff;

	private:

	UFUNCTION()
	void OnEasyDiffClicked();
	UFUNCTION()
	void OnHardDiffClicked();
};
