// Fill out your copyright notice in the Description page of Project Settings.


#include "BowShootN.h"
#include "INF_MainChar.h"
#include "INF_Weapon.h"
#include "Kismet/GameplayStatics.h"

void UBowShootN::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, const FAnimNotifyEventReference &EventReference)
{
  if(IINF_MainChar* Char = Cast<IINF_MainChar>(MeshComp->GetOwner()))
    {
      IINF_Weapon* Bow = Cast<IINF_Weapon>(Char->GetWeapon());
    if(Bow!=nullptr && !Char->IsDodging())
    {
    Bow->Shoot();
    UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(),Bow->GetAttackSound(),Cast<AActor>(Char->GetWeapon())->GetActorLocation());
    }
    }
}
