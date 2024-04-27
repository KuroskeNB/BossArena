// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTSUpdatePlayerLoc.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UBTSUpdatePlayerLoc : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	public:
	UBTSUpdatePlayerLoc();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
