// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MagicComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT2_API UMagicComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMagicComponent();

	void UseSpell();
	void UseSpellWithCast();
	UFUNCTION(BlueprintCallable)
    void ChangeSpell(TSubclassOf<class ASpells_Base> NewSpell);
	FString GetSpellName();
    
	UPROPERTY()
	bool bCanDoMagic=true;

	class UUserWidget* CastWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> SpellCastWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> SpellsWidgetClass;
	class UUserWidget* SpellsWidget;

	FTimerHandle MyTimerHandle;
	void Casting();

	UPROPERTY()
	TScriptInterface<IINF_MainChar> CompOwner;

	bool GetNeedCast();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
    TSubclassOf<class ASpells_Base> MagicImpulseClass;
    UPROPERTY(EditAnywhere)
    TSubclassOf<class ASpells_Base> MagicBlastClass;

    UPROPERTY()
    class ASpells_Base* CurrentSpell;

	bool bImpulseCD =true;
	bool bBlastCD =true;
private:

UPROPERTY(EditAnywhere)
TSubclassOf<class ASpells_Base> FirstSpellClass;

TSubclassOf<class ASpells_Base> CurrentSpellClass;

struct FTimerHandle ImpulseCD;
UPROPERTY(EditAnywhere)
float ImpulseCDtime=5;

struct FTimerHandle BlastCD;
UPROPERTY(EditAnywhere)
float BlastCDtime =5;
};
