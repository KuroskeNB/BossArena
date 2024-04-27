// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spells_Base.h"
#include "Spells_Impulse.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ASpells_Impulse : public ASpells_Base
{
	GENERATED_BODY()
	
	public:
    ASpells_Impulse();
	virtual void Activate() override;

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
    
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
     FVector NormalImpulse, const FHitResult& Hit);

	private:
	UPROPERTY(EditAnywhere)
	float DamageAmount=10;
	UPROPERTY(EditAnywhere)
	float ImpulsePower=2000;
	UPROPERTY(EditAnywhere)
	float SpellDistance=700;
	FVector StartLocation;
	UPROPERTY(VisibleAnywhere)
    class UBoxComponent* SpellZone;
	UPROPERTY(VisibleAnywhere)
class UProjectileMovementComponent* MovementComp;

class IINF_Enemy* HitChar;

UPROPERTY(EditAnywhere)
class USoundBase*ImpulseSound;
UPROPERTY(EditAnywhere)
class UParticleSystem* ExplosionParticle;
UPROPERTY(EditAnywhere)
class UParticleSystem* HitParticle;
UPROPERTY(EditAnywhere)
class UParticleSystemComponent* TraceParticle;
};
