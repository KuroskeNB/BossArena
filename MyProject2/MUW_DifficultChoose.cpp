// Fill out your copyright notice in the Description page of Project Settings.


#include "MUW_DifficultChoose.h"
#include "Kismet/GameplayStatics.h"
#include "INF_MenuGameMode.h"
#include "SharedGameInstance.h"
#include "Components/Button.h"

void UMUW_DifficultChoose::NativeConstruct()
{
    Super::NativeConstruct();
    if(EasyDiff)
    {
      EasyDiff->OnPressed.AddDynamic(this,&UMUW_DifficultChoose::OnEasyDiffClicked);
    }
    if(HardDiff)
    {
      HardDiff->OnPressed.AddDynamic(this,&UMUW_DifficultChoose::OnHardDiffClicked);
    }
}

void UMUW_DifficultChoose::OnEasyDiffClicked()
{
    if(!Cast<USharedGameInstance>(GetGameInstance())) return;
    Cast<USharedGameInstance>(GetGameInstance())->EnemyMaxHP=Cast<USharedGameInstance>(GetGameInstance())->EasyDiffHP;
    Cast<IINF_MenuController>(GetOwningPlayer())->ChooseWeapon();
}

void UMUW_DifficultChoose::OnHardDiffClicked()
{
    if(!Cast<USharedGameInstance>(GetGameInstance())) return;
    Cast<USharedGameInstance>(GetGameInstance())->EnemyMaxHP=Cast<USharedGameInstance>(GetGameInstance())->HardDiffHP;
    Cast<IINF_MenuController>(GetOwningPlayer())->ChooseWeapon();
}
