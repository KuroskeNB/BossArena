// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharBase.h"
#include "MyProject2/INF_MainChar.h"
#include "MainChar.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AMainChar : public ACharBase, public IINF_MainChar
{
	GENERATED_BODY()
	public:
	// Sets default values for this character's properties
	AMainChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Движение
	virtual void Tick(float DeltaTime) override;
    UFUNCTION(BlueprintCallable, Category = "My Functions")
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable, Category = "My Functions")
	void MoveRight(float Value);
	UFUNCTION(BlueprintCallable, Category = "My Functions")
	void MyJump();
    
	UFUNCTION()
	virtual FString GetCurrentSpellName() override;
	void WeaponAttack();
    
	void StartCharSpellChange();
    void EndCharSpellChange();
	void Roll();
    
	UFUNCTION(BlueprintCallable)
	UMagicComponent* GetMagicComponent()const; 

	IINF_Weapon* GetWeapon() const override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jump animation");
	class UAnimMontage* JumpAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Roll animation");
	class UAnimMontage* RollAnimation;
	
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;
    
	void LaunchTo();
	virtual void Rolling() override;

	void SpellCast();
    UFUNCTION(BlueprintNativeEvent)
    void StartCasting();
    virtual void StartCasting_Implementation() override;
    UFUNCTION(BlueprintNativeEvent)
	void EndCasting();
	virtual void EndCasting_Implementation() override;
	bool bIsCasting=false;

	// bool statuses
	virtual void EndDodging() override;
	virtual bool IsDodging() override;
	bool bIsDodging =false;
	
	virtual bool IsGrappling() override;
	bool bCanGrapp = true;
	UFUNCTION()
	virtual bool MainIsAlive() override;

	virtual bool GetImpulseCD() override;
	virtual bool GetBlastCD() override;

	//Work with links on the char
	virtual void PlayAnim(UAnimMontage* Animation) override;
private:

class IINF_MainController* CharController;

UPROPERTY(EditAnywhere,Category = "Char Properties" )
TSubclassOf<class AWeaponBase> DefaultWeaponClass;
UPROPERTY()
class AActor* Weapon;
class IINF_Weapon* ShareWeapon;

UPROPERTY(EditAnywhere,Category = "Char Properties")
float JumpForce=500;
UPROPERTY(EditAnywhere,Category = "Char Properties")
float GrabRadius=500;
class USkeletalMeshComponent* SkeletalMeshComponent = GetMesh();

UPROPERTY(EditAnywhere)
bool WithSword;

UPROPERTY(EditAnywhere)
class UGrapplingCable* Cable;

UPROPERTY(VisibleAnywhere)
class UMagicComponent* Magic;
UPROPERTY(VisibleAnywhere)
class UMagicComponent* Magic2;

};
