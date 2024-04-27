// Fill out your copyright notice in the Description page of Project Settings.


#include "MainController.h"
#include "Blueprint/UserWidget.h"
#include "TimerManager.h"

void AMainController::BeginPlay()
{
    Super::BeginPlay();
    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);
    SetShowMouseCursor(false);
    if(HUDWidget)
    {
      HUD = CreateWidget(this,HUDWidget);
      if(HUD)
      HUD->AddToViewport();
    }
    if(InteractWidget)
    {
      InteractHUD = CreateWidget(this,InteractWidget);
      if(InteractHUD)
      InteractHUD->AddToViewport();
    }
}

void AMainController::StartSpellChange()
{
  if(InteractHUD)
  {
  InteractHUD->SetVisibility(ESlateVisibility::Hidden);
  }
  if(SpellChangeWidget)
  {
    SpellChangeHUD = CreateWidget(this,SpellChangeWidget);
    SpellChangeHUD->AddToViewport();
    SetShowMouseCursor(true);
    FInputModeGameAndUI InputMode;
    SetInputMode(InputMode);
  }

}

void AMainController::EndSpellChange()
{
  if(SpellChangeHUD)
  {
  SpellChangeHUD->RemoveFromParent();
  }
  if(InteractHUD)
  {
    InteractHUD->SetVisibility(ESlateVisibility::Visible);
    SetShowMouseCursor(false);
    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);
  }
}

void AMainController::GameStart()
{
}

void AMainController::GameEnd(bool bIsWon)
{
  StopMovement();
  if(GameEndWidget)
  {
    FInputModeUIOnly InputMode;
    SetInputMode(InputMode);
    GameEndHUD = CreateWidget(this,GameEndWidget);
    GameEndHUD->AddToViewport();
    SetShowMouseCursor(true);
  }
  UE_LOG(LogTemp, Warning, TEXT("you in gameend"));
  if(!bIsWon)
  {
  }

}

void AMainController::JumpNotice()
{
  if(JumpNoticeWidget)
    {
      JumpNoticeHUD = CreateWidget(this,JumpNoticeWidget);
      if(JumpNoticeHUD)
      JumpNoticeHUD->AddToViewport();
      if(JumpNoticeHUD)
      {
      GetWorld()->GetTimerManager().SetTimer(MyTimerHandle,[this]()
       {
       JumpNoticeHUD->RemoveFromParent();
       },2,false);
      }
    }
  
}

void AMainController::RestartThisLevel()
{
 FTimerHandle Temp;
  GetWorldTimerManager().SetTimer(Temp,this,&APlayerController::RestartLevel,5,false);
}
