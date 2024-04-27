// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSUpdatePlayerLoc.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTSUpdatePlayerLoc::UBTSUpdatePlayerLoc()
{
}

void UBTSUpdatePlayerLoc::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp,NodeMemory,DeltaSeconds);
    APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
    if(Player==nullptr) return;
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),Player->GetActorLocation());
}
