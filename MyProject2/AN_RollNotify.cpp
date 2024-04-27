// Fill out your copyright notice in the Description page of Project Settings.


#include "AN_RollNotify.h"
#include "INF_MainChar.h"

void UAN_RollNotify::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, const FAnimNotifyEventReference &EventReference)
{
    UE_LOG(LogTemp, Warning, TEXT("Notify roll"));
  if(MeshComp->GetOwner()->GetClass()->ImplementsInterface(UINF_MainChar::StaticClass()))
  {
    Cast<IINF_MainChar>(MeshComp->GetOwner())->Rolling();
  }
}
