// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "INF_MainController.h"
#include "MainController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AMainController : public APlayerController, public IINF_MainController
{
	GENERATED_BODY()
	public:
	virtual void BeginPlay() override;

	virtual void StartSpellChange() override;
    virtual void EndSpellChange() override;

	virtual void GameStart() override;
    virtual void GameEnd(bool bIsWon) override;
    virtual void JumpNotice() override;

	virtual void RestartThisLevel() override;
	private:
    UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDWidget;
	class UUserWidget* HUD;
    
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> InteractWidget;
	class UUserWidget* InteractHUD;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> SpellChangeWidget;
	class UUserWidget* SpellChangeHUD;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> JumpNoticeWidget;
	class UUserWidget* JumpNoticeHUD;
	FTimerHandle MyTimerHandle;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> GameEndWidget;
	class UUserWidget* GameEndHUD;
};
