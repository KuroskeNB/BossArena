// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "INF_MainChar.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UINF_MainChar : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYPROJECT2_API IINF_MainChar
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    //Animations
	virtual void PlayAnim(UAnimMontage* Animation)=0;
	//Movement related functions
	UFUNCTION()
    virtual void EndDodging() = 0;
	virtual void Rolling()=0;
	UFUNCTION(BlueprintNativeEvent)
	void StartCasting();
	UFUNCTION(BlueprintNativeEvent)
	void EndCasting();
	virtual bool IsGrappling() = 0;
	virtual bool IsDodging()=0;
	virtual class IINF_Weapon* GetWeapon() const=0;
	UFUNCTION()
	virtual bool MainIsAlive()=0;

	UFUNCTION()
	virtual FString GetCurrentSpellName()=0;

	virtual bool GetImpulseCD()=0;
	virtual bool GetBlastCD()=0;
};
