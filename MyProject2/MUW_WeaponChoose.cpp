// Fill out your copyright notice in the Description page of Project Settings.


#include "MUW_WeaponChoose.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "INF_MenuGameMode.h"
#include "SharedGameInstance.h"

void UMUW_WeaponChoose::NativeConstruct()
{
    Super::NativeConstruct();
    if(ChooseSword)
    {
        ChooseSword->OnPressed.AddDynamic(this,&UMUW_WeaponChoose::OnChooseSwordClicked);
    }
    if(ChooseBow)
    {
        ChooseBow->OnPressed.AddDynamic(this,&UMUW_WeaponChoose::OnChooseBowClicked);
    }
}

void UMUW_WeaponChoose::OnChooseBowClicked()
{
    if(!Cast<USharedGameInstance>(GetGameInstance())) return;
    Cast<USharedGameInstance>(GetGameInstance())->MainWeaponClass=Cast<USharedGameInstance>(GetGameInstance())->BowClass;
    Cast<IINF_MenuGameMode>(UGameplayStatics::GetGameMode(GetOwningPlayer()->GetWorld()))->LetsBegin();
}

void UMUW_WeaponChoose::OnChooseSwordClicked()
{
    if(!Cast<USharedGameInstance>(GetGameInstance())) return;
    Cast<USharedGameInstance>(GetGameInstance())->MainWeaponClass=Cast<USharedGameInstance>(GetGameInstance())->SwordClass;
    Cast<IINF_MenuGameMode>(UGameplayStatics::GetGameMode(GetOwningPlayer()->GetWorld()))->LetsBegin();
}
