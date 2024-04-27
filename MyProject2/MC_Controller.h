// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "INF_MenuController.h"
#include "MC_Controller.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AMC_Controller : public APlayerController, public IINF_MenuController
{
	GENERATED_BODY()
	public:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void ChooseWeapon() override;
	UFUNCTION()
	virtual void ChooseDifficult() override;
	private:
    UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> StartWidget;
	class UUserWidget* StartHUD;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> DifficultWidget;
	class UUserWidget* DifficultHUD;
    
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WeaponWidget;
	class UUserWidget* WeaponHUD;
};
