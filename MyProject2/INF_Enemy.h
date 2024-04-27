// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "INF_Enemy.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UINF_Enemy : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYPROJECT2_API IINF_Enemy
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

  virtual void EnemyAttack()=0;
  virtual void AnimAttack() =0;
  virtual void SlowDown()=0;
  virtual void MyJump()=0;
  virtual float GetAttackRange()=0;
  virtual class USoundBase* GetGroundSound()=0;
  virtual class UParticleSystem* GetGroundParticle()=0;
};
