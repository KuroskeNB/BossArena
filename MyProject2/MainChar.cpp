// Fill out your copyright notice in the Description page of Project Settings.


#include "MainChar.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GrapplingCable.h"
#include "TimerManager.h"
#include "MagicComponent.h"
#include "INF_Weapon.h"
#include "INF_MainController.h"
#include "FCharacterData.h"
#include "SharedGameInstance.h"

// Sets default values
AMainChar::AMainChar() : Super()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    //Camera View creating
   SpringArm= CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
   SpringArm->SetupAttachment(RootComponent);
   SpringArm->TargetArmLength=500.0f;
   Camera=CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
   Camera->SetupAttachment(SpringArm);

   Cable = CreateDefaultSubobject<UGrapplingCable>(TEXT("My Cable"));
   Cable->SetupAttachment(RootComponent);

   SpringArm->bUsePawnControlRotation=true;
   Camera->bUsePawnControlRotation=false;

   //Camera settings
   bUseControllerRotationPitch=false;
   bUseControllerRotationYaw=true;
   bUseControllerRotationRoll=false;
    
   
}

// Called when the game starts or when spawned
void AMainChar::BeginPlay()
{
	Super::BeginPlay();
   
    
    // components implementing
    Magic = FindComponentByClass<UMagicComponent>();
    Cable = FindComponentByClass<UGrapplingCable>();
    //Weapon implementing
    if(Cast<USharedGameInstance>(GetGameInstance()) && Cast<USharedGameInstance>(GetGameInstance())->MainWeaponClass)
    {
     Weapon=GetWorld()->SpawnActor<AActor>(Cast<USharedGameInstance>(GetGameInstance())->MainWeaponClass);
    }
    else
    {
     Weapon=GetWorld()->SpawnActor<AActor>(DefaultWeaponClass);
    }
    // Weapon creating
    if(Weapon)
    {
    Weapon->SetOwner(this);
    Weapon->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
    ShareWeapon = Cast<IINF_Weapon>(Weapon);
    }
    
    if(Controller)
    CharController = Cast<IINF_MainController>(Controller);
}

// Called every frame
void AMainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
PlayerInputComponent->BindAxis("MoveForwardBack",this,&AMainChar::MoveForward);
PlayerInputComponent->BindAxis("MoveRightLeft",this,&AMainChar::MoveRight);
PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&AMainChar::MyJump);

PlayerInputComponent->BindAxis("TurnUpDown",this,&AMainChar::AddControllerPitchInput);
PlayerInputComponent->BindAxis("TurnRightLeft",this,&AMainChar::AddControllerYawInput);

PlayerInputComponent->BindAction("Interact",IE_Pressed,this,&AMainChar::LaunchTo);

PlayerInputComponent->BindAction("Attack",IE_Pressed,this,&AMainChar::WeaponAttack);
PlayerInputComponent->BindAction("SpellCast",IE_Pressed,this,&AMainChar::SpellCast);
PlayerInputComponent->BindAction("Roll",IE_Pressed,this,&AMainChar::Roll);

PlayerInputComponent->BindAction("SpellChange",IE_Pressed,this,&AMainChar::StartCharSpellChange);
PlayerInputComponent->BindAction("SpellChange",IE_Released,this,&AMainChar::EndCharSpellChange);
}

void AMainChar::MoveForward(float Value)
{
    if (Controller != nullptr && Value != 0.0f)
    {
        AddMovementInput(GetActorForwardVector(), Value);
    }
}

void AMainChar::MoveRight(float Value)
{
    if (Controller != nullptr && Value != 0.0f)
    {
        AddMovementInput(GetActorRightVector(), Value);
    }
    
}

void AMainChar::MyJump(){
    if(GetCharacterMovement()->IsFalling()) return;
	if (Controller != nullptr && CanJump() && !bIsCasting &&!bIsDodging){
        LaunchCharacter(GetActorUpVector() * JumpForce, false, true);
	}
	if(JumpAnimation)
	PlayAnimMontage(JumpAnimation,1.0,NAME_None);
}

FString AMainChar::GetCurrentSpellName()
{
    if(this==nullptr) return TEXT("No Magic");
    if(Magic->CurrentSpell!=nullptr){
    return Magic->GetSpellName();
    }
    return TEXT("No Magic");
}

void AMainChar::WeaponAttack()
{
    if(!bIsDodging)
    ShareWeapon->Attack();
}

void AMainChar::StartCharSpellChange()
{
    if(CharController)
    {
        CharController->StartSpellChange();
    }
}

void AMainChar::EndCharSpellChange()
{
    if(CharController)
    {
        CharController->EndSpellChange();
    }
}

void AMainChar::Roll()
{
    if(RollAnimation && !bIsDodging && !GetCharacterMovement()->IsFalling() && !bIsCasting)
    {
	PlayAnimMontage(RollAnimation,1.0,NAME_None);
    bIsDodging = true;
    }
}

UMagicComponent* AMainChar::GetMagicComponent() const
{
return Magic;
}

IINF_Weapon * AMainChar::GetWeapon() const
{
return ShareWeapon;
}

void AMainChar::LaunchTo()
{
 if(Cable)
    {
     Cable->LaunchTo();
    }
}

void AMainChar::Rolling()
{
    LaunchCharacter(GetLastMovementInputVector()*2000,false,false);
}

void AMainChar::SpellCast()
{
    if(Magic==nullptr) return;
    if (Magic->GetNeedCast()) 
    {
        Magic->UseSpellWithCast();			
	}
    else 
    {
     Magic->UseSpell();
    }
}


void AMainChar::StartCasting_Implementation()
{
    bIsCasting=true;
}

void AMainChar::EndCasting_Implementation()
{
    bIsCasting=false;
}


void AMainChar::EndDodging()
{
    bIsDodging=false;
}

bool AMainChar::IsDodging()
{
return bIsDodging;
}

bool AMainChar::IsGrappling()
{
    return Cable->bIsGrappling;
}

bool AMainChar::MainIsAlive()
{
    return Health>0;
}

bool AMainChar::GetImpulseCD()
{
    return Magic->bImpulseCD;
}

bool AMainChar::GetBlastCD()
{
    return Magic->bBlastCD;
}

void AMainChar::PlayAnim(UAnimMontage *Animation)
{
    PlayAnimMontage(Animation,1.0,NAME_None);
}
