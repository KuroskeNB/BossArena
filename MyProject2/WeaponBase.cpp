// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "INF_MainChar.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	RootComponent = Capsule;
	Mesh=CreateDefaultSubobject<USkeletalMeshComponent>("Static Mesh");
	Mesh->SetupAttachment(Capsule);
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::LineTrace()
{
}


void AWeaponBase::Attack()
{
	if(bIsAnimating) return;
    IINF_MainChar* Char = Cast<IINF_MainChar>(GetOwner());
  if(AttackAnimation && !bIsAttacking && Char)
  {
    bIsAttacking = true;
    bIsAnimating = true;
    Char->PlayAnim(AttackAnimation);
  }
}

void AWeaponBase::Shoot()
{
  //empty interface function
}

USoundBase *AWeaponBase::GetAttackSound()
{
  //empty interface function
    return nullptr;
}
