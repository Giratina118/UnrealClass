// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "myCPPBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLASS_240622_API UmyCPPBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, category = "MyCPPLibrary")
	static float myCPPSin(float rad);
};
