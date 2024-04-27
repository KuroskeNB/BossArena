// Fill out your copyright notice in the Description page of Project Settings.


#include "Game_Throne.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
// Sets default values
AGame_Throne::AGame_Throne()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
	ThroneMesh=CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent=ThroneMesh;
	Box=CreateDefaultSubobject<UBoxComponent>("Box Collision");
	Box->SetupAttachment(ThroneMesh);
}

// Called when the game starts or when spawned
void AGame_Throne::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGame_Throne::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

