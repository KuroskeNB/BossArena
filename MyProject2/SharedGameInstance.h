// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SharedGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API USharedGameInstance : public UGameInstance
{
	GENERATED_BODY()
	public: 
	UPROPERTY(EditAnywhere,Category = "Char Properties" )
    TSubclassOf<class AWeaponBase> BowClass;
	UPROPERTY(EditAnywhere,Category = "Char Properties" )
    TSubclassOf<class AWeaponBase> SwordClass;

	TSubclassOf<class AWeaponBase> MainWeaponClass;
	TSubclassOf<class AWeaponBase> GetWeaponClass();

	float EnemyMaxHP;
	UPROPERTY(EditAnywhere)
	float EasyDiffHP=200;
	UPROPERTY(EditAnywhere)
	float HardDiffHP=350;
};
