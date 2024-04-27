// Fill out your copyright notice in the Description page of Project Settings.


#include "CharBase.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "INF_MainController.h"
#include "INF_MainChar.h"
#include "INF_Enemy.h"
// Sets default values
ACharBase::ACharBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health=MaxHealth;
}

void ACharBase::OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
	UE_LOG(LogTemp, Display, TEXT("onhit char"));
}

bool ACharBase::IsAlive() const
{
    return Health>0;
}

float ACharBase::GetHpPercent()
{
    return Health/MaxHealth;
}

// Called when the game starts or when spawned
void ACharBase::BeginPlay()
{
	Super::BeginPlay();
	Health=MaxHealth;
}

// Called every frame
void ACharBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ACharBase::TakeDamage(float Damage, FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser)
{
	if(ImpactParticle)
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactParticle,GetActorLocation(),FRotator(0,180,0));
	if(Damage<Health)
	{
	Health-=Damage;
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("death"));
		Health=0;
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		if(GetController() && Cast<IINF_MainChar>(GetController()->GetPawn()))
		{
			UE_LOG(LogTemp, Warning, TEXT("you in inf maincontroller"));
			Cast<IINF_MainController>(UGameplayStatics::GetPlayerController(GetWorld(),0))->GameEnd(false);
		}
		else if(GetController() &&Cast<IINF_Enemy>(GetController()->GetPawn()))
		{
            Cast<IINF_MainController>(UGameplayStatics::GetPlayerController(GetWorld(),0))->GameEnd(true);
		}
		DetachFromControllerPendingDestroy();
	}
	UE_LOG(LogTemp, Display, TEXT("%s health is %f"),*GetActorNameOrLabel(),Health);
    return 0.0f;
}

// Called to bind functionality to input
void ACharBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

