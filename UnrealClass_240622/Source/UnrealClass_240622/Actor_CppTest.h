// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "kismet/kismetSystemLibrary.h"

#include "Actor_CppTest.generated.h"

UCLASS(Blueprintable)
class UNREALCLASS_240622_API AActor_CppTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActor_CppTest();

	UPROPERTY(BlueprintReadWrite)
	int myInt;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float myFloat;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTransform myTransform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString myString;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void myFirstFunction();

};
