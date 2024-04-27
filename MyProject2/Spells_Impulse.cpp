// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells_Impulse.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "INF_Enemy.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Particles/ParticleSystemComponent.h"

ASpells_Impulse::ASpells_Impulse()
{
    PrimaryActorTick.bCanEverTick = true;
    SpellZone = CreateDefaultSubobject<UBoxComponent>("Box Component");
    RootComponent=SpellZone;
    MovementComp =CreateDefaultSubobject<UProjectileMovementComponent>("Movement Component");
    TraceParticle = CreateDefaultSubobject<UParticleSystemComponent>("Trace Particle");
    TraceParticle->SetupAttachment(RootComponent);
}

void ASpells_Impulse::Activate()
{
if(!FindComponentByClass<UBoxComponent>()) {
    return;
}
    FVector Location;
    FRotator Rotation;
    APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if(OwnerPawn == nullptr) return;

    OwnerPawn->GetController()->GetPlayerViewPoint(Location,Rotation);
    Location += Rotation.Vector() * 700; 
    SetActorLocation(Location);
    StartLocation=Location;
    FVector LaunchDirection = Rotation.Vector();
    MovementComp->Velocity = LaunchDirection * MovementComp->InitialSpeed;

    // Optionally, you can also set the projectile's initial rotation
    SetActorRotation(LaunchDirection.Rotation());
    UGameplayStatics::PlaySoundAtLocation(GetWorld(),ImpulseSound,GetActorLocation());
    if(ExplosionParticle)
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ExplosionParticle,Location,LaunchDirection.Rotation());
}

void ASpells_Impulse::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(FVector::Dist(GetActorLocation(),StartLocation)>=SpellDistance && !StartLocation.IsZero())
    {
        UE_LOG(LogTemp, Warning, TEXT("distance spell %f"),FVector::Dist(GetActorLocation(),StartLocation));
        Destroy();
    }
}

void ASpells_Impulse::BeginPlay()
{
    Super::BeginPlay();
    if(FindComponentByClass<UBoxComponent>())
    {
        SpellZone=FindComponentByClass<UBoxComponent>();
    SpellZone->OnComponentHit.AddDynamic(this,&ASpells_Impulse::OnHit);
    }
}

void ASpells_Impulse::OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
    HitChar = Cast<IINF_Enemy>(Hit.GetActor());
    if(HitParticle)
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),HitParticle,Hit.ImpactPoint);
        if(HitChar)
        {
            
            UE_LOG(LogTemp, Display, TEXT("You hit char"));
            UE_LOG(LogTemp, Display, TEXT("Damage is %f an"),DamageAmount);
            HitChar->SlowDown();
        UGameplayStatics::ApplyDamage(Hit.GetActor(), DamageAmount, GetInstigatorController(), this, UDamageType::StaticClass());
        Destroy();
        }
}
