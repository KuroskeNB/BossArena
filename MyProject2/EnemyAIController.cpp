// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Prediction.h"
#include "Perception/AISense_Prediction.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"

void AEnemyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

AEnemyAIController::AEnemyAIController()
{
  SetupPerceptionSystem();
}

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Display, TEXT("Your message1"));
    Perceptions->OnTargetPerceptionUpdated.AddDynamic(this,&AEnemyAIController::OnPrediction);
    if(AIBehavior!=nullptr)
    {
        UE_LOG(LogTemp, Display, TEXT("Your message"));
        RunBehaviorTree(AIBehavior);
        APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
        GetBlackboardComponent()->SetValueAsObject("Player",Player);
        GetBlackboardComponent()->SetValueAsVector("PlayerLocation",Player->GetActorLocation());
    }
    
}

void AEnemyAIController::OnPrediction(AActor* Actor, FAIStimulus Stimulus)
{
    if(Actor){
    UAISense_Prediction::RequestControllerPredictionEvent(this,Actor,PredictionTime);
    GetBlackboardComponent()->SetValueAsVector("PlayerLocation",Stimulus.StimulusLocation);}
}


void AEnemyAIController::SetupPerceptionSystem()
{
    UE_LOG(LogTemp, Display, TEXT("piska"));
    SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>("Perception Component"));
    Perceptions=GetPerceptionComponent();
    PredictionConfig = CreateDefaultSubobject<UAISenseConfig_Prediction>("Prediction Config");
    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight Config");
    Perceptions->ConfigureSense(*SightConfig);
    Perceptions->ConfigureSense(*PredictionConfig);
    Perceptions->SetDominantSense(SightConfig->GetSenseImplementation());
}
