// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_GameEnd.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "INF_MainController.h"
#include "SharedGameInstance.h"
#include "INF_MainChar.h"

void UUW_GameEnd::NativeConstruct()
{
    Super::NativeConstruct();
    if(SwitchWeapon)
    {
      SwitchWeapon->OnPressed.AddDynamic(this,&UUW_GameEnd::OnSwitchWeaponClicked);
    }
    if(RestartGame)
    {
      RestartGame->OnPressed.AddDynamic(this,&UUW_GameEnd::OnRestartGameClicked);
    }
    if(BowWeapon)
    {
        BowWeapon->SetVisibility(ESlateVisibility::Hidden);
        BowWeapon->OnPressed.AddDynamic(this,&UUW_GameEnd::OnBowWeaponClicked);
    }
    if(SwordWeapon)
    {
        SwordWeapon->SetVisibility(ESlateVisibility::Hidden);
        SwordWeapon->OnPressed.AddDynamic(this,&UUW_GameEnd::OnSwordWeaponClicked);
    }
    if(WinText && Cast<IINF_MainChar>(GetOwningPlayer()->GetPawn())->MainIsAlive())
    {
        if(FailText)
        FailText->SetVisibility(ESlateVisibility::Hidden);

    }
    else
    {
        if(FailText)
        WinText->SetVisibility(ESlateVisibility::Hidden);
    }

  if(ChangeDiff)
  {
    ChangeDiff->OnPressed.AddDynamic(this,&UUW_GameEnd::OnChangeDiffClicked);
    if(EasyDiff)
    {
    EasyDiff->SetVisibility(ESlateVisibility::Hidden);
    EasyDiff->OnPressed.AddDynamic(this,&UUW_GameEnd::OnEasyDiffClicked);
    }
    if(HardDiff)
    {
    HardDiff->SetVisibility(ESlateVisibility::Hidden);
    HardDiff->OnPressed.AddDynamic(this,&UUW_GameEnd::OnHardDiffClicked);
    }
  }
}

void UUW_GameEnd::OnSwitchWeaponClicked()
{
    if(BowWeapon)
  BowWeapon->SetVisibility(ESlateVisibility::Visible);
  if(SwordWeapon)
  SwordWeapon->SetVisibility(ESlateVisibility::Visible);
}

void UUW_GameEnd::OnRestartGameClicked()
{
  Cast<IINF_MainController>(UGameplayStatics::GetPlayerController(GetOwningPlayer()->GetWorld(),0))->RestartThisLevel();
}

void UUW_GameEnd::OnSwordWeaponClicked()
{
    if(!Cast<USharedGameInstance>(GetGameInstance())) return;
    Cast<USharedGameInstance>(GetGameInstance())->MainWeaponClass=Cast<USharedGameInstance>(GetGameInstance())->SwordClass;
    SwordWeapon->SetVisibility(ESlateVisibility::Hidden);
    if(BowWeapon)
    BowWeapon->SetVisibility(ESlateVisibility::Hidden);
}

void UUW_GameEnd::OnBowWeaponClicked()
{
    if(!Cast<USharedGameInstance>(GetGameInstance())) return;
    Cast<USharedGameInstance>(GetGameInstance())->MainWeaponClass=Cast<USharedGameInstance>(GetGameInstance())->BowClass;
    BowWeapon->SetVisibility(ESlateVisibility::Hidden);
    if(SwordWeapon)
    SwordWeapon->SetVisibility(ESlateVisibility::Hidden);
}

void UUW_GameEnd::OnChangeDiffClicked()
{
 if(EasyDiff)
  EasyDiff->SetVisibility(ESlateVisibility::Visible);
 if(HardDiff)
  HardDiff->SetVisibility(ESlateVisibility::Visible);
}

void UUW_GameEnd::OnEasyDiffClicked()
{
if(!Cast<USharedGameInstance>(GetGameInstance())) return;
    Cast<USharedGameInstance>(GetGameInstance())->EnemyMaxHP=Cast<USharedGameInstance>(GetGameInstance())->EasyDiffHP;
  if(EasyDiff)
  EasyDiff->SetVisibility(ESlateVisibility::Hidden);
 if(HardDiff)
  HardDiff->SetVisibility(ESlateVisibility::Hidden);
}

void UUW_GameEnd::OnHardDiffClicked()
{
  if(!Cast<USharedGameInstance>(GetGameInstance())) return;
    Cast<USharedGameInstance>(GetGameInstance())->EnemyMaxHP=Cast<USharedGameInstance>(GetGameInstance())->HardDiffHP;
  if(EasyDiff)
  EasyDiff->SetVisibility(ESlateVisibility::Hidden);
 if(HardDiff)
  HardDiff->SetVisibility(ESlateVisibility::Hidden);
}
