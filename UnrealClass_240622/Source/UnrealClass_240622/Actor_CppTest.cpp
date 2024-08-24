// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor_CppTest.h"

// Sets default values
AActor_CppTest::AActor_CppTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActor_CppTest::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("BeginPlay"), true, true, 
		FLinearColor::Blue, 4.0f);
	UE_LOG(LogTemp, Log, TEXT("BeginPlay"));
}

void AActor_CppTest::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	// 기능 작성
}

// Called every frame
void AActor_CppTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActor_CppTest::myFirstFunction()
{
}

