// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Arrow.generated.h"

UCLASS()
class MYPROJECT2_API AArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
     FVector NormalImpulse, const FHitResult& Hit);
    void Test();

private:
UPROPERTY(EditAnywhere)
float DamageAmount = 25;
UPROPERTY(EditAnywhere)
class UStaticMeshComponent* ArrowMesh;
UPROPERTY(VisibleAnywhere)
class UProjectileMovementComponent* MovementComp;
};
