// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_FastJump.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UBTT_FastJump : public UBTTaskNode
{
	GENERATED_BODY()
	public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	void EnemyJump();
	void JumpAttack();
	FVector TargetLocation;
    struct FTimerHandle MyTimerHandle;
	class APawn* Owner;
};
