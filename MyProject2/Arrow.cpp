// Fill out your copyright notice in the Description page of Project Settings.


#include "Arrow.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "INF_Enemy.h"

// Sets default values
AArrow::AArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    ArrowMesh=CreateDefaultSubobject<UStaticMeshComponent>("Arrow Mesh");
	RootComponent = ArrowMesh;
	MovementComp =CreateDefaultSubobject<UProjectileMovementComponent>("Movement Component");
	MovementComp->InitialSpeed=1300;
	MovementComp->MaxSpeed=1500;
	MovementComp->ProjectileGravityScale = 0.5f;
}

// Called when the game starts or when spawned
void AArrow::BeginPlay()
{
	Super::BeginPlay();
	ArrowMesh->OnComponentHit.AddDynamic(this,&AArrow::OnHit);
}

// Called every frame
void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArrow::OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
	UE_LOG(LogTemp, Display, TEXT("Your hit"));
	IINF_Enemy* HitChar = Cast<IINF_Enemy>(Hit.GetActor());
        if(HitChar)
        {
            UE_LOG(LogTemp, Display, TEXT("You hit char"));
            UE_LOG(LogTemp, Display, TEXT("Damage is %f an"),DamageAmount);
        UGameplayStatics::ApplyDamage(Hit.GetActor(), DamageAmount, GetInstigatorController(), this, UDamageType::StaticClass());
        }
		Destroy();
}

void AArrow::Test()
{
}
