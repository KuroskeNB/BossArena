// Fill out your copyright notice in the Description page of Project Settings.


#include "MUW_MainMenu.h"
#include "INF_MenuController.h"
#include "Components/Button.h"

void UMUW_MainMenu::NativeConstruct()
{
    Super::NativeConstruct();
    if(StartGame)
    {
      StartGame->OnPressed.AddDynamic(this,&UMUW_MainMenu::OnStartGameClicked);
    }
    if(ExitGame)
    {
      UE_LOG(LogTemp, Warning, TEXT("exitgame"));
      ExitGame->OnPressed.AddDynamic(this,&UMUW_MainMenu::OnExitGameClicked);
    }
}

void UMUW_MainMenu::OnExitGameClicked()
{
  UE_LOG(LogTemp, Display, TEXT("quit"));
  GetOwningPlayer()->ConsoleCommand("Quit");
}

void UMUW_MainMenu::OnStartGameClicked()
{
 Cast<IINF_MenuController>(GetOwningPlayer())->ChooseDifficult();
}
