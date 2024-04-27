// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "RogueEnemy.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ARogueEnemy : public AEnemyBase
{
	GENERATED_BODY()
	public:

	virtual void AnimAttack() override;
	virtual void EnemyAttack() override;
};
