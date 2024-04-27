// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "SharedGameInstance.h"

void AEnemyBase::BeginPlay()
{
    Super::BeginPlay();
    if(!Cast<USharedGameInstance>(GetGameInstance())->EnemyMaxHP)
    {
    Health=MaxHealth;
    }
    else
    {
      Health=Cast<USharedGameInstance>(GetGameInstance())->EnemyMaxHP;
    }

}

void AEnemyBase::EnemyAttack()
{
}

void AEnemyBase::AnimAttack()
{

}

float AEnemyBase::GetAttackRange()
{
    return AttackRange;
}

USoundBase *AEnemyBase::GetGroundSound()
{
    return nullptr;
}

UParticleSystem *AEnemyBase::GetGroundParticle()
{
    return nullptr;
}

void AEnemyBase::SlowDown()
{
    GetCharacterMovement()->MaxWalkSpeed*=0.5;
    GetWorld()->GetTimerManager().SetTimer(MyCDTimer,[this]()
    {
    GetCharacterMovement()->MaxWalkSpeed*=2;
    },SlowDownTime, false);
}

void AEnemyBase::MoveForward(float Value)
{
    if (Controller != nullptr && Value != 0.0f)
    {
        // Определите вектор направления (например, ForwardVector)
        const FVector Direction = GetActorForwardVector();

        // Используйте функцию AddMovementInput для передвижения вперед
        AddMovementInput(Direction, Value);
    }
}

void AEnemyBase::MoveRight(float Value)
{
    if (Controller != nullptr && Value != 0.0f)
    {
        // Определите вектор направления влево и вправо
        const FVector Direction = GetActorRightVector();

        // Используйте функцию AddMovementInput для движения влево и вправо
        AddMovementInput(Direction, Value);
    }
}

void AEnemyBase::MyJump(){
	if (Controller != nullptr && CanJump()){
        FVector JumpDirection = GetActorUpVector(); // Направление прыжка (вверх)
        LaunchCharacter(JumpDirection * JumpForce, false, true);
	}
	if(JumpAnimation)
	PlayAnimMontage(JumpAnimation,1.0,NAME_None);
}