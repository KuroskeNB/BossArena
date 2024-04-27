// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponSword.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AWeaponSword : public AWeaponBase
{
	GENERATED_BODY()
	public:

    float AttackDuration;
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
	virtual void LineTrace() override;
	
	virtual void Attack() override;

	virtual class USoundBase* GetAttackSound() override;
	
	private: 
	bool bHasHit = false;
	UPROPERTY(EditAnywhere)
	float DamageAmount = 25;
	UPROPERTY(EditAnywhere)
    int AttackRange = 200;
	UPROPERTY(EditAnywhere)
	class USoundBase*SwingSound;
	UPROPERTY(EditAnywhere)
	class USoundBase* DamageSound;
};
