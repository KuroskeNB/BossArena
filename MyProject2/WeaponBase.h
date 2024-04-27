// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "INF_Weapon.h"
#include "WeaponBase.generated.h"

UCLASS()
class MYPROJECT2_API AWeaponBase : public AActor, public IINF_Weapon
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    virtual void LineTrace() override;

    virtual void Attack() override;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attack animation");
	UAnimMontage* AttackAnimation;
    
	virtual void Shoot() override;
	virtual class USoundBase* GetAttackSound() override;

	UPROPERTY(BlueprintReadWrite)
	bool bIsAttacking = false;
	UPROPERTY(BlueprintReadWrite)
	bool bIsAnimating =false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
UPROPERTY(VisibleAnywhere)
class UCapsuleComponent* Capsule; 
UPROPERTY(VisibleAnywhere)
class USkeletalMeshComponent* Mesh; 
private:

};
