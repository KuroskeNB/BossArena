// Fill out your copyright notice in the Description page of Project Settings.


#include "AN_EndRoll.h"
#include "INF_MainChar.h"
void UAN_EndRoll::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, const FAnimNotifyEventReference &EventReference)
{
  if(MeshComp->GetOwner()->GetClass()->ImplementsInterface(UINF_MainChar::StaticClass()))
  {
    UE_LOG(LogTemp, Warning, TEXT("end roll notify"));
    Cast<IINF_MainChar>(MeshComp->GetOwner())->EndDodging();
  }
}
