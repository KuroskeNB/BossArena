// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "INF_MainController.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UINF_MainController : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYPROJECT2_API IINF_MainController
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
virtual void GameStart()=0;
virtual void GameEnd(bool bIsWon)=0;
virtual void JumpNotice()=0;
virtual void StartSpellChange()=0;
virtual void EndSpellChange()=0;

virtual void RestartThisLevel()=0;
};
