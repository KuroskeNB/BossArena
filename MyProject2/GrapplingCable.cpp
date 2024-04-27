// Fill out your copyright notice in the Description page of Project Settings.


#include "GrapplingCable.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"

void UGrapplingCable::BeginPlay()
{
    Super::BeginPlay();
    SetVisibility(false);
	Owner=UGameplayStatics::GetPlayerCharacter(GetWorld(),0);
}

UGrapplingCable::UGrapplingCable()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UGrapplingCable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGrapplingCable::LaunchTo()
{
	if(bCanGrapp==false) return;

    //implements properties
    FVector Location;
    FRotator Rotation;
    Owner->GetController()->GetPlayerViewPoint(Location,Rotation);
    FVector CustomEndLocation = Location+ Rotation.Vector() * LaunchDistance;
    FHitResult HitResult;
    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(Owner);

    //grappling system
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult,Location,CustomEndLocation,ECC_Visibility,CollisionParams);
    if(bHit){
    TargetLocation = HitResult.ImpactPoint;

    if(CableHitSound)
    UGameplayStatics::PlaySoundAtLocation(GetWorld(),CableHitSound,TargetLocation);

    this->SetVisibility(true);
    //Smooth grappling
    GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UGrapplingCable::Grappling, GetWorld()->GetDeltaSeconds()*0.1, true);
    //statuses
    bCanGrapp=false;
    bIsGrappling=true;
    // cooldown
    GetWorld()->GetTimerManager().SetTimer(CDTimerHandle,[this](){bCanGrapp=true;},2,false);
    }
}

void UGrapplingCable::Grappling()
{
    if(TargetLocation !=FVector::ZeroVector)
  {
        FVector CableLocation = GetComponentLocation();
        // Mathematic
        float DistanceToTarget = FVector::Dist(Owner->GetActorLocation(), TargetLocation);
        
        //End of grappling
        if (DistanceToTarget <= GrapRadius)
        {
            UE_LOG(LogTemp, Display, TEXT("Your grap"));
            GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
            SetVisibility(false);
            bIsGrappling=false;
        }
        else //grappling mechanic
        {
           
            FVector CurrentLocation = Owner->GetActorLocation();

        // Searching fo direction
        FVector PullDirection = (TargetLocation - CurrentLocation).GetSafeNormal();
        if(LoadSound)
        UGameplayStatics::PlaySoundAtLocation(GetWorld(),LoadSound,CurrentLocation);
        // Searchingg for new character position
        FVector NewLocation = CurrentLocation + PullDirection * LaunchSpeed * GetWorld()->GetDeltaSeconds();

        // Movement
        SetWorldLocation(TargetLocation);
        Owner->SetActorLocation(NewLocation);
        }
}
}
