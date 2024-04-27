// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_FastJump.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "INF_Enemy.h"
#include "INF_MainChar.h"
#include "INF_MainController.h"

EBTNodeResult::Type UBTT_FastJump::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
    if(!Player) return EBTNodeResult::Type();
    AAIController* Controller = OwnerComp.GetAIOwner();
    Owner = Controller->GetPawn();
    Cast<IINF_Enemy>(Owner)->MyJump();
    IINF_MainController* PlayerController = Cast<IINF_MainController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
    if(Player)
    TargetLocation=OwnerComp.GetBlackboardComponent()->GetValueAsVector("PlayerLocation");
    GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UBTT_FastJump::EnemyJump, GetWorld()->GetDeltaSeconds()*0.1, true,0.15);
    PlayerController->JumpNotice();
    return EBTNodeResult::Type();
}

void UBTT_FastJump::EnemyJump()
{
    float DistanceToTarget = FVector::Dist(Owner->GetActorLocation(), TargetLocation);

        if (DistanceToTarget <= 130)
        {
            UE_LOG(LogTemp, Display, TEXT("Your grap"));
            GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
            JumpAttack();
            UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),Cast<IINF_Enemy>(Owner)->GetGroundParticle(),(Owner->GetActorLocation()-FVector(0,0,130)));
            UGameplayStatics::SpawnSoundAtLocation(GetWorld(),Cast<IINF_Enemy>(Owner)->GetGroundSound(),(Owner->GetActorLocation()-FVector(0,0,100)));
        } 
        else
        {
           
            FVector CurrentLocation = Owner->GetActorLocation();

        // Вычисляем направление к целевой позиции
        FVector PullDirection = (TargetLocation - CurrentLocation).GetSafeNormal();

        // Рассчитываем новую позицию для персонажа
        FVector NewLocation = CurrentLocation + PullDirection * 500 * GetWorld()->GetDeltaSeconds();

        Owner->SetActorLocation(NewLocation);
        }
}

void UBTT_FastJump::JumpAttack()
{
    FVector StartLocation = Owner->GetActorLocation();
    float Radius = 200.0f; // Радиус круга
    float HalfHeight = 200.0f; // Половина высоты круга
    FQuat Rotation = FQuat::Identity;
    FCollisionShape CollisionShape = FCollisionShape::MakeCapsule(Radius, HalfHeight);

    // Настройка параметров лучевой трассировки
    FCollisionQueryParams TraceParams;
    TraceParams.bTraceComplex = true;
    TraceParams.bReturnPhysicalMaterial = false;
    TraceParams.AddIgnoredActor(Owner);

    // Выполнение лучевой трассировки
    FHitResult HitResult;
    bool bHit = GetWorld()->SweepSingleByChannel(HitResult, StartLocation, StartLocation, Rotation, ECC_GameTraceChannel1, CollisionShape, TraceParams);
    if(bHit)
    {
    IINF_MainChar* HitChar = Cast<IINF_MainChar>(HitResult.GetActor());
    if(HitChar)
    {
    UE_LOG(LogTemp, Display, TEXT("heavy attack"));
    UGameplayStatics::ApplyDamage(HitResult.GetActor(), 20, Owner->GetInstigatorController(), Owner, UDamageType::StaticClass());
    }
    }
}
