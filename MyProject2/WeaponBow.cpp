// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBow.h"
#include "Components/SceneComponent.h"
#include "Arrow.h"

AWeaponBow::AWeaponBow()
{
  PrimaryActorTick.bCanEverTick = true;

  ArrowSpawn =CreateDefaultSubobject<USceneComponent>("Arrow Spawn");
  ArrowSpawn->SetupAttachment(Mesh);
}

void AWeaponBow::LineTrace()
{
  //empty interface function
}

USoundBase *AWeaponBow::GetAttackSound()
{
  //empty interface function
  return ShootSound;
}

void AWeaponBow::Shoot()
{
    UE_LOG(LogTemp, Display, TEXT("Your message"));
    FVector Location;
    FRotator Rotation;
    APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if(OwnerPawn == nullptr || OwnerPawn->GetController()==nullptr) return;
    OwnerPawn->GetController()->GetPlayerViewPoint(Location,Rotation);
    Location += Rotation.Vector() * 500; 

    GetWorld()->SpawnActor<AArrow>(ArrowClass,Location,Rotation);
}
