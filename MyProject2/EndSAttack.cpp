// Fill out your copyright notice in the Description page of Project Settings.


#include "EndSAttack.h"
#include "MainChar.h"
#include "WeaponSword.h"

void UEndSAttack::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, const FAnimNotifyEventReference &EventReference)
{
  auto MeshOwner = MeshComp->GetOwner();
  if(AMainChar* Char = Cast<AMainChar>(MeshOwner))
    {
      AWeaponSword* Sword = Cast<AWeaponSword>(Char->GetWeapon());
    if(Sword!=nullptr)
    {
    UE_LOG(LogTemp, Display, TEXT("is not attacking"));
    Sword->bIsAnimating=false;
    Sword->bIsAttacking=false;
    }
    }
}
