// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	public:
	virtual void Tick(float DeltaTime) override;
    
	AEnemyAIController();
	protected:
    virtual void BeginPlay() override;
	UFUNCTION()
	void OnPrediction(AActor* Actor, FAIStimulus Stimulus);

	UFUNCTION()
	void SetupPerceptionSystem();
	private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
    
	class UAIPerceptionComponent* Perceptions;

	class UAISenseConfig_Prediction* PredictionConfig;
	class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(EditAnywhere)
	float PredictionTime=2;
};
