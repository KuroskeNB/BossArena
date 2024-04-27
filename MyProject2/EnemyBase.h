// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharBase.h"
#include "INF_Enemy.h"
#include "EnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AEnemyBase : public ACharBase, public IINF_Enemy
{
	GENERATED_BODY()
	public:

	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jump animation");
	class UAnimMontage* JumpAnimation;

	virtual void EnemyAttack() override;
	virtual void AnimAttack() override;
	virtual float GetAttackRange() override;

	virtual class USoundBase* GetGroundSound() override;
  virtual class UParticleSystem* GetGroundParticle() override;

	UPROPERTY(EditAnywhere,Category = "Combat") 
	float AttackRange = 150;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat");
	TArray<class UAnimMontage*> AttackAnimation;
	
    virtual void SlowDown();
	struct FTimerHandle MyCDTimer;

	UFUNCTION(BlueprintCallable, Category = "My Functions")
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable, Category = "My Functions")
	void MoveRight(float Value);
	UFUNCTION(BlueprintCallable, Category = "My Functions")
	virtual void MyJump() override;
	private:
	UPROPERTY(EditAnywhere,Category = "Char Properties")
float JumpForce=500;
    UPROPERTY(EditAnywhere)
	float SlowDownTime = 6;
};
