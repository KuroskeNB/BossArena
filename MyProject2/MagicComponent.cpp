// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicComponent.h"
#include "Spells_Base.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Controller.h"
#include "UW_BlastCast.h"
#include "TimerManager.h"
#include "INF_MainChar.h"
#include "UW_SpellSystem.h"

// Sets default values for this component's properties
UMagicComponent::UMagicComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

void UMagicComponent::ChangeSpell(TSubclassOf<class ASpells_Base> NewSpell)
{
	if(!bCanDoMagic) return;
    // Spell class implementing
	CurrentSpellClass = NewSpell;
	// Garbage cleaning
    if (CurrentSpell != nullptr)
    {
    CurrentSpell->ConditionalBeginDestroy();
	CurrentSpell = nullptr;
    }
	// Spell creating
    if(CurrentSpellClass)
    CurrentSpell = NewObject<ASpells_Base>(this, CurrentSpellClass, NAME_None, RF_NoFlags, nullptr);
}

void UMagicComponent::UseSpell()
{
	//valid check
	if(!bCanDoMagic || !GetOwner()|| !CurrentSpell || !CurrentSpellClass || 
	!GetOwner()->GetClass()->ImplementsInterface(UINF_MainChar::StaticClass()) || !Cast<IINF_MainChar>(GetOwner())
	|| !bImpulseCD)  return;
	
	// Spell activating
	ASpells_Base* SpawnedSpell=GetWorld()->SpawnActor<ASpells_Base>(CurrentSpellClass);
	SpawnedSpell->SetOwner(GetOwner());
	SpawnedSpell->Activate();
	// Status
    bImpulseCD=false;
    // Spell Cooldown
	GetWorld()->GetTimerManager().SetTimer(ImpulseCD, [this]()
	{
	 bImpulseCD=true;
	}, ImpulseCDtime, false);
}

void UMagicComponent::UseSpellWithCast()
{
	//valid check
	if(!bCanDoMagic || !GetOwner()|| !CurrentSpell || !CurrentSpellClass || 
	!GetOwner()->GetClass()->ImplementsInterface(UINF_MainChar::StaticClass()) || !bBlastCD)  return;
    
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UMagicComponent::Casting, 2.0f, false);
	if(SpellCastWidget)
	{
    UE_LOG(LogTemp, Warning, TEXT("SpellCastWidget"));
    CastWidget = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(),0),SpellCastWidget);
	}
	if (CastWidget)
	{
		CastWidget->AddToViewport();
	}
	// Status
	if(bCanDoMagic)
	bCanDoMagic = false;
    
	//Start casting by using interface
	if (GetOwner()->GetClass()->ImplementsInterface(UINF_MainChar::StaticClass()))
	{
		IINF_MainChar::Execute_StartCasting(GetOwner());
	}	
}

FString UMagicComponent::GetSpellName()
{
	if (CurrentSpell && !CurrentSpell->SpellName.IsEmpty())
    {
        return CurrentSpell->SpellName;
    }
	return TEXT("No Spell");
}

void UMagicComponent::Casting()
{
	//Set statuses
	bCanDoMagic=true;
	//End casting by using interface
	if (GetOwner()->GetClass()->ImplementsInterface(UINF_MainChar::StaticClass()))
	{
		IINF_MainChar::Execute_EndCasting(GetOwner());
	}	
	GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
	//Using spell
	ASpells_Base* SpawnedSpell=GetWorld()->SpawnActor<ASpells_Base>(CurrentSpellClass);
	SpawnedSpell->SetOwner(GetOwner());
	SpawnedSpell->Activate();
	//Set statuses and CD
	bBlastCD=false;
	GetWorld()->GetTimerManager().SetTimer(BlastCD, [this]()
	{
	 bBlastCD=true;
    }, BlastCDtime, false);
}

// Called when the game starts
void UMagicComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentSpellClass = FirstSpellClass;
	//innit Cast widget to game
	//adding spell to scene
	if(CurrentSpellClass)
	{
	CurrentSpell = NewObject<ASpells_Base>(this, CurrentSpellClass, NAME_None, RF_NoFlags, nullptr);
	}
	//getting owner
	if(GetOwner())
	{
    CompOwner.SetObject(GetOwner()); // BroadcastListener is of type TScriptInterface
    CompOwner.SetInterface(Cast<IINF_MainChar>(GetOwner()));
	}

}


// Called every frame
void UMagicComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UMagicComponent::GetNeedCast()
{
    return CurrentSpell->bNeedCast;
}
