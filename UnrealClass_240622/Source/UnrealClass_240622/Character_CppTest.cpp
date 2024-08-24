// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_CppTest.h"

// Sets default values
ACharacter_CppTest::ACharacter_CppTest()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacter_CppTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacter_CppTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacter_CppTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

