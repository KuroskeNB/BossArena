// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spells_Base.h"
#include "Spells_MagicBlast.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ASpells_MagicBlast : public ASpells_Base
{
	GENERATED_BODY()
	public:


	virtual void Activate() override;
    void AfterCast();
	ASpells_MagicBlast();
	class UUserWidget* CastWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> SpellCastWidget;
	FTimerHandle MyTimerHandle;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
     FVector NormalImpulse, const FHitResult& Hit);
	
	protected:

	virtual void BeginPlay() override;

	private:
	UPROPERTY(EditAnywhere)
	float DamageAmount = 50;
	
	UPROPERTY(EditAnywhere)
	class USoundBase* BlastSound;
    UPROPERTY(EditAnywhere)
	class USoundBase* BlastHitSound;
	UPROPERTY(EditAnywhere)
    class UParticleSystem* ExplosionParticle;
	UPROPERTY(EditAnywhere)
    class UParticleSystem* HitParticle;

	UPROPERTY(EditAnywhere)
class UStaticMeshComponent* BlastMesh;
UPROPERTY(VisibleAnywhere)
class UProjectileMovementComponent* MovementComp;
};
