// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_BlastCast.h"
#include "Components/ProgressBar.h"
#include "TimerManager.h"

void UUW_BlastCast::NativeConstruct()
{
 Super::NativeConstruct();
 UE_LOG(LogTemp, Warning, TEXT("You have no castbar"));
 if (Casting)
 {
  UE_LOG(LogTemp, Warning, TEXT("You have castbar"));
  Casting->SetPercent(0.0f);
  GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UUW_BlastCast::Cast, 0.05f, true);
 }
}

void UUW_BlastCast::NativeTick(const FGeometry &MyGeometry, float InDeltaTime)
{

}

void UUW_BlastCast::Cast()
{
    Casting->SetPercent(Casting->GetPercent()+0.025f);
  if(Casting->GetPercent()>=1.0f)
  {
    UE_LOG(LogTemp, Display, TEXT("remove"));
    GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
    RemoveFromParent();
  }
}
