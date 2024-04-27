// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	APawn* MyChar;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float Speed;
};
