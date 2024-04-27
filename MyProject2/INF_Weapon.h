// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "INF_Weapon.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UINF_Weapon : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYPROJECT2_API IINF_Weapon
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
virtual void LineTrace() =0;
virtual void Attack() =0;
virtual void Shoot()=0;
virtual class USoundBase* GetAttackSound()=0;
};
