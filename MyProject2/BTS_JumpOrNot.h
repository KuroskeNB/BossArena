// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_JumpOrNot.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UBTS_JumpOrNot : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	public:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	bool bCantJump =false;
	struct FTimerHandle CDTimer;
    
	UPROPERTY(EditAnywhere)
	float CDTime = 2.5;
	UPROPERTY(EditAnywhere)
	float JumpDist = 550;
};
