// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"
void AMainMenuGameMode::LetsBegin()
{
  UGameplayStatics::OpenLevel(this, "Demonstration");
}
