// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponBow.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AWeaponBow : public AWeaponBase
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable)
	virtual void Shoot() override;
    AWeaponBow();

	virtual void LineTrace() override;
	virtual class USoundBase* GetAttackSound() override;
    
	private:
	UPROPERTY(EditAnywhere,Category = "Char Properties" )
    TSubclassOf<class AArrow> ArrowClass;
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* ArrowSpawn;

	UPROPERTY(EditAnywhere)
class USoundBase*ShootSound;
};
