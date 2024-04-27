// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharBase.generated.h"

UCLASS()
class MYPROJECT2_API ACharBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharBase();
    
	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    FVector NormalImpulse, const FHitResult& Hit);
	
	UFUNCTION(BlueprintPure)
	bool IsAlive() const;

    UFUNCTION(BlueprintCallable)
	float GetHpPercent();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100;
	float Health;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UAnimMontage* DeathAnim;
	UPROPERTY(EditAnywhere)
	class UParticleSystem* ImpactParticle;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
	UFUNCTION(BlueprintCallable, Category = "Combat")
    float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
