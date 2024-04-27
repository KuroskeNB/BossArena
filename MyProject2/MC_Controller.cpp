// Fill out your copyright notice in the Description page of Project Settings.


#include "MC_Controller.h"
#include "Blueprint/UserWidget.h"

void AMC_Controller::BeginPlay()
{
    FInputModeUIOnly InputMode;
    SetInputMode(InputMode);
    SetShowMouseCursor(true);
    if(StartWidget)
    {
        StartHUD=CreateWidget(this,StartWidget);
        if(StartHUD)
        StartHUD->AddToViewport();
    }
    if(WeaponWidget)
    {
        WeaponHUD = CreateWidget(this,WeaponWidget);
    }
    if(DifficultWidget)
    {
        DifficultHUD = CreateWidget(this,DifficultWidget);
    }
}

void AMC_Controller::ChooseWeapon()
{
    if(WeaponHUD && DifficultHUD)
    {
        DifficultHUD->RemoveFromParent();
        WeaponHUD->AddToViewport();
    }
}

void AMC_Controller::ChooseDifficult()
{
    if(DifficultHUD && StartHUD)
    {
        StartHUD->RemoveFromParent();
        DifficultHUD->AddToViewport();
    }
}
