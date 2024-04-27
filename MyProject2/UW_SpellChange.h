// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_SpellChange.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UUW_SpellChange : public UUserWidget
{
	GENERATED_BODY()
	public:
    virtual void NativeConstruct() override;
    UPROPERTY(BlueprintReadWrite,meta = (BindWidgetOptional))
    class UButton * MagicBlast;
	protected:
    UPROPERTY(meta = (BindWidgetOptional))
    class UButton * MagicImpulse;
    UPROPERTY(meta = (BindWidgetOptional))
    class UButton * OptionsBtn;
    
	UFUNCTION()
	void OnMagicBlastClicked();
	UFUNCTION()
	void OnMagicImpulseClicked();
	private:
};
