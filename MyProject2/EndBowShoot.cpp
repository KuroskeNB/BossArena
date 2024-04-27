// Fill out your copyright notice in the Description page of Project Settings.


#include "EndBowShoot.h"
#include "MainChar.h"
#include "WeaponBow.h"

void UEndBowShoot::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, const FAnimNotifyEventReference &EventReference)
{
  auto MeshOwner = MeshComp->GetOwner();
  if(AMainChar* Char = Cast<AMainChar>(MeshOwner))
    {
      AWeaponBow* Bow = Cast<AWeaponBow>(Char->GetWeapon());
    if(Bow!=nullptr)
    {
    Bow->bIsAttacking=false;
    Bow->bIsAnimating=false;
    UE_LOG(LogTemp, Display, TEXT("is not shooting"));
    }
    }
}
