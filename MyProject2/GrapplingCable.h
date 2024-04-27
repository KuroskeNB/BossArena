// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CableComponent.h"
#include "GrapplingCable.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UGrapplingCable : public UCableComponent
{
	GENERATED_BODY()
	protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    
    class ACharacter* Owner;

	UPROPERTY(EditAnywhere)
	class USoundBase* LoadSound;

	UPROPERTY(EditAnywhere)
	class USoundBase* CableHitSound;

    bool IsGrapping;
    UPROPERTY(EditAnywhere)
    float GrapRadius =100.0f;

	UPROPERTY(EditAnywhere)
    float LaunchDistance = 1000;
    UPROPERTY(EditAnywhere)
    float LaunchSpeed = 1000;

    FVector TargetLocation;
    struct FTimerHandle MyTimerHandle;
    struct FTimerHandle CDTimerHandle;
public:	
UGrapplingCable();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void LaunchTo();
	void Grappling();

	bool bCanGrapp = true;

	bool bIsGrappling=false;
};
