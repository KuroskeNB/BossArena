// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "INF_MenuGameMode.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UINF_MenuGameMode : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYPROJECT2_API IINF_MenuGameMode
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
UFUNCTION()
virtual void LetsBegin()=0;
};
