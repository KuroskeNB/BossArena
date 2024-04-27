// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_SpellSystem.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UUW_SpellSystem : public UUserWidget
{
	GENERATED_BODY()
	public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidgetOptional))
	class UTextBlock*BlastReady;
	UPROPERTY(meta = (BindWidgetOptional))
	class UTextBlock*ImpulseReady;

	UPROPERTY(meta = (BindWidgetOptional))
	class UTextBlock*CurrentSpell;

	void BlastCDReady();
	void BlastCDNotReady();

	void ImpulseCDReady();
	void ImpulseCDNotReady();
};
