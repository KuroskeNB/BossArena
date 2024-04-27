// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "INF_MenuGameMode.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AMainMenuGameMode : public AGameModeBase, public IINF_MenuGameMode
{
	GENERATED_BODY()
	public:
	
	virtual void LetsBegin() override;
};
