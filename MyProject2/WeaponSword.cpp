// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponSword.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimInstance.h"
#include "INF_Enemy.h"
#include "INF_MainChar.h"


void AWeaponSword::BeginPlay()
{
    Super::BeginPlay();
    AttackDuration = AttackAnimation->GetPlayLength();
}

void AWeaponSword::LineTrace()
{
    if(!bIsAttacking) return;
    FVector StartLocation = GetActorLocation();
    FVector EndLocation = GetActorLocation()+GetActorForwardVector()*AttackRange;
    

    FHitResult HitResult;
    FCollisionQueryParams TraceParams;
    TraceParams.AddIgnoredActor(this);
    TraceParams.AddIgnoredActor(GetOwner());

    GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation,ECC_GameTraceChannel1,TraceParams);
    if(HitResult.bBlockingHit)
    {
        if(DamageSound)
	UGameplayStatics::PlaySoundAtLocation(GetWorld(),DamageSound,GetActorLocation());
        bIsAttacking=false;
        UE_LOG(LogTemp, Display, TEXT("You hit %s"),*HitResult.GetActor()->GetActorNameOrLabel());
        if(HitResult.GetActor()->GetClass()->ImplementsInterface(UINF_Enemy::StaticClass()))
        {
            UE_LOG(LogTemp, Display, TEXT("You hit char"));
            UE_LOG(LogTemp, Display, TEXT("Damage is %f an"),DamageAmount);
        UGameplayStatics::ApplyDamage(HitResult.GetActor(), DamageAmount, GetInstigatorController(), this, UDamageType::StaticClass());
        }
    }
}

void AWeaponSword::Attack()
{
    if(bIsAnimating) return;
    IINF_MainChar* Char = Cast<IINF_MainChar>(GetOwner());
  if(AttackAnimation && !bIsAttacking && Char)
  {
    bIsAttacking = true;
    bIsAnimating = true;
    Char->PlayAnim(AttackAnimation);
  }
}

USoundBase *AWeaponSword::GetAttackSound()
{
    if(SwingSound)
    return SwingSound;
    UE_LOG(LogTemp, Warning, TEXT("no swingsound"));
    return nullptr;
}
