// Fill out your copyright notice in the Description page of Project Settings.


#include "AN_EnemyPunch.h"
#include "BTTask_Attack.h"
#include "INF_Enemy.h"


void UAN_EnemyPunch::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, const FAnimNotifyEventReference &EventReference)
{
    if(MeshComp->GetOwner()->GetClass()->ImplementsInterface(UINF_Enemy::StaticClass()))
  {
    Cast<IINF_Enemy>(MeshComp->GetOwner())->EnemyAttack();
  }
}
