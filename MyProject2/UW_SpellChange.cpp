// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_SpellChange.h"
#include "MainChar.h"
#include "Components/Button.h"
#include "MagicComponent.h"

void UUW_SpellChange::NativeConstruct()
{
    Super::NativeConstruct();
    if(MagicBlast)
    {
     MagicBlast->OnPressed.AddDynamic(this,&UUW_SpellChange::OnMagicBlastClicked);
    }
    if(MagicImpulse)
    {
     MagicImpulse->OnPressed.AddDynamic(this,&UUW_SpellChange::OnMagicImpulseClicked);
    }
}

void UUW_SpellChange::OnMagicBlastClicked()
{
  UMagicComponent* MagComp = Cast<AMainChar>(GetOwningPlayerPawn())->GetMagicComponent();
  MagComp->ChangeSpell(MagComp->MagicBlastClass);
}

void UUW_SpellChange::OnMagicImpulseClicked()
{
    UMagicComponent* MagComp = Cast<AMainChar>(GetOwningPlayerPawn())->GetMagicComponent();
  MagComp->ChangeSpell(MagComp->MagicImpulseClass);
}
