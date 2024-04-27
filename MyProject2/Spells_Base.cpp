// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells_Base.h"

// Sets default values
ASpells_Base::ASpells_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpells_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpells_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpells_Base::Activate()
{
	UE_LOG(LogTemp, Display, TEXT("spell activated"));
}
