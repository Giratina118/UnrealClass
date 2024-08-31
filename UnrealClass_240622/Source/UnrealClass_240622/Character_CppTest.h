// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character_CppTest.generated.h"

DECLARE_DELEGATE(MySingleCast);
DECLARE_DELEGATE_OneParam(MySingleCast_OneParam, int);

DECLARE_MULTICAST_DELEGATE(MyMultiCast);

UCLASS()
class UNREALCLASS_240622_API ACharacter_CppTest : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacter_CppTest();

	MySingleCast SomeEvent;
	MySingleCast_OneParam SomeEvent_OneParam;

	MyMultiCast SomeEvent_Multi;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void FireBullet();
	void MoveRight(float value);
};
