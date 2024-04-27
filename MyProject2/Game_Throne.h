// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game_Throne.generated.h"

UCLASS()
class MYPROJECT2_API AGame_Throne : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGame_Throne();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

UPROPERTY(EditAnywhere)
float Health=250;

UPROPERTY(EditAnywhere)
class UStaticMeshComponent* ThroneMesh;
UPROPERTY(EditAnywhere)
class UBoxComponent* Box;
};
