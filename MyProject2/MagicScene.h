// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MagicScene.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT2_API UMagicScene : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMagicScene();

	void UseSpell();
	void UseSpellWithCast();
	UFUNCTION(BlueprintCallable)
    void ChangeSpell(TSubclassOf<class ASpells_Base> NewSpell);
	FString GetSpellName();

	bool bCanDoMagic=true;

	class UUserWidget* CastWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> SpellCastWidget;
	FTimerHandle MyTimerHandle;
	void Casting();

	class IINF_MainChar* CompOwner;

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
private:

UPROPERTY(EditAnywhere)
TSubclassOf<class ASpells_Base> FirstSpellClass;

TSubclassOf<class ASpells_Base> CurrentSpellClass;


};
