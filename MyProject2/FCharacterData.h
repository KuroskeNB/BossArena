// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include"FCharacterData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MYPROJECT2_API FCharacterData : public FTableRowBase
{
public:
GENERATED_USTRUCT_BODY()
UPROPERTY(EditAnywhere)
float DataCheck =0;
	FCharacterData();
	~FCharacterData();
};
