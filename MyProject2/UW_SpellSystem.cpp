// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_SpellSystem.h"
#include "Components/TextBlock.h"
#include "INF_MainChar.h"

void UUW_SpellSystem::NativeTick(const FGeometry & MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry,InDeltaTime);
    if(!GetOwningPlayer() || !GetOwningPlayer()->GetPawn()) return;
    if(CurrentSpell &&GetOwningPlayer()->GetPawn()->GetClass()->ImplementsInterface(UINF_MainChar::StaticClass()))
    {
        CurrentSpell->SetText(FText::FromString(Cast<IINF_MainChar>(GetOwningPlayer()->GetPawn())->GetCurrentSpellName()));
    }
    else
    {
     CurrentSpell->SetText(FText::FromString("Mo Magic"));
    }
    
    if(Cast<IINF_MainChar>(GetOwningPlayer()->GetPawn())->GetBlastCD())
    {
        BlastCDReady();
    }
    else
    {
      BlastCDNotReady();
    }
    if(Cast<IINF_MainChar>(GetOwningPlayer()->GetPawn())->GetImpulseCD())
    {
        ImpulseCDReady();
    }
    else
    {
      ImpulseCDNotReady();
    }
}

void UUW_SpellSystem::NativeConstruct()
{
    Super::NativeConstruct();
    if(BlastReady)
    {
     ImpulseReady->SetVisibility(ESlateVisibility::Visible);
    }
    if(ImpulseReady)
    {
     ImpulseReady->SetVisibility(ESlateVisibility::Visible);
    }
}

void UUW_SpellSystem::BlastCDReady()
{
    if(BlastReady)
    {
     BlastReady->SetVisibility(ESlateVisibility::Visible);
    }
}

void UUW_SpellSystem::BlastCDNotReady()
{
    if(BlastReady)
    {
     BlastReady->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UUW_SpellSystem::ImpulseCDReady()
{
    if(ImpulseReady)
    {
     ImpulseReady->SetVisibility(ESlateVisibility::Visible);
    }
}

void UUW_SpellSystem::ImpulseCDNotReady()
{
    if(ImpulseReady)
    {
     ImpulseReady->SetVisibility(ESlateVisibility::Hidden);
    }
}
