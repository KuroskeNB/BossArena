// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spells_Base.generated.h"

UCLASS()
class MYPROJECT2_API ASpells_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpells_Base();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	bool bNeedCast=false;

    virtual void Activate();
    UPROPERTY(EditAnywhere)
	FString SpellName = "Spell Base";
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
