// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_JumpOrNot.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "INF_MainChar.h"
#include "AIController.h"

void UBTS_JumpOrNot::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    IINF_MainChar *Player=Cast<IINF_MainChar>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
    AAIController* Controller = OwnerComp.GetAIOwner();
 if(!Player) return;
 if(!Player->IsGrappling() &&
 FVector::Distance(Controller->GetPawn()->GetActorLocation(),UGameplayStatics::GetPlayerPawn(GetWorld(),0)->GetActorLocation())>JumpDist ||
 !bCantJump){
   OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(),true);
    bCantJump=true;
    GetWorld()->GetTimerManager().SetTimer(CDTimer,[this]()
    {
      bCantJump=false;
      GetWorld()->GetTimerManager().ClearTimer(CDTimer);
    },CDTime,false);
 }
 else
 {
    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
 }
}
