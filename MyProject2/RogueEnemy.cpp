// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueEnemy.h"

void ARogueEnemy::AnimAttack()
{
    if(AttackAnimation.Num()<2) return;
    if(FMath::RandBool()){
        UE_LOG(LogTemp, Display, TEXT("AttackAnimation[0]"));
    PlayAnimMontage(AttackAnimation[0],1.0,NAME_None);}
    else{PlayAnimMontage(AttackAnimation[1],1.0,NAME_None);
    UE_LOG(LogTemp, Display, TEXT("AttackAnimation[1]"));}
    UE_LOG(LogTemp, Display, TEXT("rogue attack"));
}

void ARogueEnemy::EnemyAttack()
{
}
