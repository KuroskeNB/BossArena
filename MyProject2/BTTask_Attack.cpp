// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "EnemyBase.h"
#include "EnemyAIController.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    AEnemyBase* OwnerPawn = Cast<AEnemyBase>(OwnerComp.GetAIOwner()->GetPawn());
    if(OwnerPawn==nullptr || OwnerPawn->AttackAnimation[0]==nullptr) EBTNodeResult::Aborted;
    OwnerPawn->AnimAttack();

    return EBTNodeResult::Succeeded;
}
