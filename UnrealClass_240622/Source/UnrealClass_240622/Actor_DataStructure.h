// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_DataStructure.generated.h"

UCLASS()
class UNREALCLASS_240622_API AActor_DataStructure : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActor_DataStructure();

	TArray<FString> StrArr = { TEXT("Hello"), TEXT("World") , TEXT("!") };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
