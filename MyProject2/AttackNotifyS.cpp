// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackNotifyS.h"
#include "INF_MainChar.h"
#include "INF_Weapon.h"
#include "Kismet/GameplayStatics.h"


void UAttackNotifyS::NotifyTick(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, float FrameDeltaTime)
{

    auto MeshOwner = MeshComp->GetOwner();
    if(IINF_MainChar* Char = Cast<IINF_MainChar>(MeshOwner))
    {
    IINF_Weapon* Sword = Cast<IINF_Weapon>(Char->GetWeapon());
    if(Sword!=nullptr && !Char->IsDodging())
    {
    Sword->LineTrace();
    }
    }
}

void UAttackNotifyS::NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration)
{
    UE_LOG(LogTemp, Display, TEXT("attack notify begin"));
    auto MeshOwner = MeshComp->GetOwner();
    if(IINF_MainChar* Char = Cast<IINF_MainChar>(MeshOwner))
    {
    IINF_Weapon* Sword = Cast<IINF_Weapon>(Char->GetWeapon());
    if(Sword!=nullptr&& !Char->IsDodging())
    {
        UE_LOG(LogTemp, Display, TEXT("You intop sword notify"));
    UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(),Sword->GetAttackSound(),Cast<AActor>(Char->GetWeapon())->GetActorLocation());
    }
    }
}
