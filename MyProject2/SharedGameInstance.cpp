// Fill out your copyright notice in the Description page of Project Settings.


#include "SharedGameInstance.h"

TSubclassOf<class AWeaponBase> USharedGameInstance::GetWeaponClass()
{
    return MainWeaponClass;
}
