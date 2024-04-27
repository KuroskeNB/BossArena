// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_BlastCast.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UUW_BlastCast : public UUserWidget
{
	GENERATED_BODY()
	public:
	virtual void NativeConstruct() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
    class UProgressBar* Casting;
	struct FTimerHandle MyTimerHandle;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	void Cast();

};
