// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells_MagicBlast.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "INF_Enemy.h"
#include "Sound/SoundBase.h"


ASpells_MagicBlast::ASpells_MagicBlast(){

PrimaryActorTick.bCanEverTick = true;
BlastMesh=CreateDefaultSubobject<UStaticMeshComponent>("BlastMesh");
RootComponent=BlastMesh;
MovementComp =CreateDefaultSubobject<UProjectileMovementComponent>("Movement Component");
}

void ASpells_MagicBlast::Activate()
{
    UE_LOG(LogTemp, Warning, TEXT("Magic Blast"));
    if(BlastMesh==nullptr) return;
    FVector Location;
    FRotator Rotation;
    APawn* OwnerPawn = Cast<APawn>(GetOwner());
    if(OwnerPawn->GetController() == nullptr) return;
    
    OwnerPawn->GetController()->GetPlayerViewPoint(Location,Rotation);
    Location += Rotation.Vector() * 700; 
    SetActorLocation(Location);
    FVector LaunchDirection = Rotation.Vector();
    MovementComp->Velocity = LaunchDirection * MovementComp->InitialSpeed;

    // Optionally, you can also set the projectile's initial rotation
    SetActorRotation(LaunchDirection.Rotation());
    if(BlastSound)
    UGameplayStatics::PlaySoundAtLocation(GetWorld(),BlastSound,Location);
    if(ExplosionParticle)
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ExplosionParticle,Location,LaunchDirection.Rotation());
}

void ASpells_MagicBlast::AfterCast()
{
}

void ASpells_MagicBlast::OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
    UE_LOG(LogTemp, Display, TEXT("blast hit"));
    if(BlastHitSound)
    UGameplayStatics::PlaySoundAtLocation(GetWorld(),BlastHitSound,this->GetActorLocation());
    if(HitParticle)
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),HitParticle,Hit.ImpactPoint);
    if(Hit.GetActor()->GetClass()->ImplementsInterface(UINF_Enemy::StaticClass()))
  {
    UE_LOG(LogTemp, Display, TEXT("You hit char"));
     UE_LOG(LogTemp, Display, TEXT("Damage is %f an"),DamageAmount);
     UGameplayStatics::ApplyDamage(Hit.GetActor(), DamageAmount, GetInstigatorController(), this, UDamageType::StaticClass());
    }
    Destroy();
}

void ASpells_MagicBlast::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("blast begin"));
    BlastMesh->OnComponentHit.AddDynamic(this,&ASpells_MagicBlast::OnHit);
}
