// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "HeavyEnemy.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AHeavyEnemy : public AEnemyBase
{
	GENERATED_BODY()
	public:
	virtual void EnemyAttack() override;
    virtual void AnimAttack() override;

	virtual class USoundBase* GetGroundSound() override;
  virtual class UParticleSystem* GetGroundParticle() override;
	private:
	UPROPERTY(EditAnywhere)
	float Damage = 30;

	UPROPERTY(EditAnywhere)
class USoundBase*PunchSound;
UPROPERTY(EditAnywhere)
class USoundBase*GroundSound;
UPROPERTY(EditAnywhere)
class UParticleSystem* GroundedParticle;
UPROPERTY(EditAnywhere)
class UParticleSystem* PunchParticle;
};
