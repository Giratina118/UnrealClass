// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_CppTest.h"
#include "kismet/kismetSystemLibrary.h"
#include "Arrow.h"

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

	PlayerInputComponent->BindAction("FireBullet", IE_Pressed, this, &ACharacter_CppTest::FireBullet);
	PlayerInputComponent->BindAxis("myMoveRight", this, &ACharacter_CppTest::MoveRight);

}

void ACharacter_CppTest::FireBullet()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Fire!"), true, true,
		FLinearColor::Blue, 4.0f);
	if (SomeEvent.IsBound())
	{
		SomeEvent.Execute();
	}
	if (SomeEvent_OneParam.IsBound())
	{
		SomeEvent_OneParam.Execute(5);
	}
	if (SomeEvent_Multi.IsBound())
	{
		SomeEvent_Multi.Broadcast();
	}

	GetWorld()->SpawnActor<AArrow>(FVector::ZeroVector, FRotator::ZeroRotator);
}

void ACharacter_CppTest::MoveRight(float value)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("MoveRight"), true, true, 
		FLinearColor::Blue, GetWorld()->DeltaTimeSeconds);
}

