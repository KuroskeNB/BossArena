// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ConcageGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AConcageGameMode : public AGameModeBase
{
	GENERATED_BODY()
	public:
	virtual void BeginPlay() override;

    void GameEnd(bool bIsWin);
};
