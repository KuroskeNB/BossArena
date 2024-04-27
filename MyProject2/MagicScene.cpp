// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicScene.h"
#include "Spells_Base.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Controller.h"
#include "UW_BlastCast.h"
#include "TimerManager.h"
#include "INF_MainChar.h"

// Sets default values for this component's properties
UMagicScene::UMagicScene()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

void UMagicScene::ChangeSpell(TSubclassOf<class ASpells_Base> NewSpell)
{
	if(!bCanDoMagic) return;
	UE_LOG(LogTemp, Warning, TEXT("Before destroying CurrentSpell"));
	CurrentSpellClass = NewSpell;
if (CurrentSpell != nullptr)
{
    CurrentSpell->ConditionalBeginDestroy();
	CurrentSpell = nullptr;
}
CurrentSpell = NewObject<ASpells_Base>(this, CurrentSpellClass, NAME_None, RF_NoFlags, nullptr);
if(CurrentSpell)
{
	UE_LOG(LogTemp, Warning, TEXT("Spell changed to %s"),*CurrentSpell->SpellName);
}
}

void UMagicScene::UseSpell()
{
	if(!bCanDoMagic || !GetOwner()|| !CurrentSpell || !CurrentSpellClass || 
	!GetOwner()->GetClass()->ImplementsInterface(UINF_MainChar::StaticClass()) || !Cast<IINF_MainChar>(GetOwner()))  return;
	if(!CurrentSpell->bNeedCast){
	   ASpells_Base* SpawnedSpell=GetWorld()->SpawnActor<ASpells_Base>(CurrentSpellClass);
	   SpawnedSpell->SetOwner(GetOwner());
	   SpawnedSpell->Activate();
	}
	else
	{
      UseSpellWithCast();
	}	
}

void UMagicScene::UseSpellWithCast()
{
	IINF_MainChar* YourInterface = Cast<IINF_MainChar>(GetOwner());
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UMagicScene::Casting, 2.0f, false);
      if(CastWidget)
	  {
      CastWidget->AddToViewport();
	  }
      if(GetOwner())
	  {
		YourInterface->StartCasting();
	  }
	bCanDoMagic=false;
}

FString UMagicScene::GetSpellName()
{
	if (CurrentSpell && !CurrentSpell->SpellName.IsEmpty())
    {
        return CurrentSpell->SpellName;
    }
	else if(!CurrentSpell->SpellName.IsEmpty())
	{
		return TEXT("you have only the spell name");
	}
	return TEXT("No Spell");
}

void UMagicScene::Casting()
{
	bCanDoMagic=true;
	Cast<IINF_MainChar>(GetOwner())->EndCasting();
	GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
	ASpells_Base* SpawnedSpell=GetWorld()->SpawnActor<ASpells_Base>(CurrentSpellClass);
	SpawnedSpell->SetOwner(GetOwner());
	SpawnedSpell->Activate();
}

// Called when the game starts
void UMagicScene::BeginPlay()
{
	Super::BeginPlay();
	CurrentSpellClass = FirstSpellClass;
	//innit Cast widget to game
	if(SpellCastWidget)
	{
    UE_LOG(LogTemp, Warning, TEXT("SpellCastWidget"));
    CastWidget = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(),0),SpellCastWidget);
	}
	//adding spell to scene
	if(CurrentSpellClass)
	{
	CurrentSpell = NewObject<ASpells_Base>(this, CurrentSpellClass, NAME_None, RF_NoFlags, nullptr);
	}
	//getting owner
	if(GetOwner())
	CompOwner = Cast<IINF_MainChar>(GetOwner());
}


// Called every frame
void UMagicScene::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
