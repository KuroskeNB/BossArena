// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_InAttackRange.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "INF_Enemy.h"

void UBTS_InAttackRange::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp,NodeMemory,DeltaSeconds);
    IINF_Enemy* OwnerPawn = Cast<IINF_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
    if(OwnerPawn == nullptr) return;

    APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
    if(Player==nullptr)
    {
    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    return;
    }
    float Distance = FVector::Distance(OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(),Player->GetActorLocation());
    if(Distance<=OwnerPawn->GetAttackRange())
    {
    OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(),true);
    }
    else{
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
}
