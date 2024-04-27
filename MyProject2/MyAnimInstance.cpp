// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

void UMyAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
    MyChar=TryGetPawnOwner();
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
    if(MyChar!=nullptr)
    Speed=MyChar->GetVelocity().Size();
}
