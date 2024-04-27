// Fill out your copyright notice in the Description page of Project Settings.


#include "HeavyEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

void AHeavyEnemy::EnemyAttack()
{

    FVector StartLocation = GetActorLocation();
    float Radius = 200.0f; // Радиус круга
    float HalfHeight = 200.0f; // Половина высоты круга
    FQuat Rotation = FQuat::Identity;
    FCollisionShape CollisionShape = FCollisionShape::MakeCapsule(Radius, HalfHeight);

    // Настройка параметров лучевой трассировки
    FCollisionQueryParams TraceParams(FName(TEXT("RadialTrace")), true, this);
    TraceParams.bTraceComplex = true;
    TraceParams.bReturnPhysicalMaterial = false;
    TraceParams.AddIgnoredActor(this);

    // Выполнение лучевой трассировки
    FHitResult HitResult;
    bool bHit = GetWorld()->SweepSingleByChannel(HitResult, StartLocation, StartLocation, Rotation, ECC_GameTraceChannel1, CollisionShape, TraceParams);
    if(bHit)
    {
    ACharBase* HitChar = Cast<ACharBase>(HitResult.GetActor());
    if(HitChar!=nullptr)
    {
    UE_LOG(LogTemp, Display, TEXT("heavy attack"));
    UGameplayStatics::ApplyDamage(HitChar, Damage, GetInstigatorController(), this, UDamageType::StaticClass());
    }
    if(PunchSound)
    UGameplayStatics::PlaySoundAtLocation(GetWorld(),PunchSound,GetActorLocation());
    if(PunchParticle)
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),PunchParticle,GetActorLocation());
}
}

void AHeavyEnemy::AnimAttack()
{
    if(AttackAnimation.Num()<2) return;
    if(FMath::RandBool()){
        UE_LOG(LogTemp, Display, TEXT("AttackAnimation[0]"));
    PlayAnimMontage(AttackAnimation[0],1.0,NAME_None);}
    else{PlayAnimMontage(AttackAnimation[1],1.0,NAME_None);
    UE_LOG(LogTemp, Display, TEXT("AttackAnimation[1]"));}
    UE_LOG(LogTemp, Display, TEXT("rogue attack"));
}

USoundBase *AHeavyEnemy::GetGroundSound()
{
    return GroundSound;
}

UParticleSystem *AHeavyEnemy::GetGroundParticle()
{
    return GroundedParticle;
}
