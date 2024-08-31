// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor_DataStructure.h"
#include "kismet/kismetSystemLibrary.h"
#include "EngineUtils.h"

// Sets default values
AActor_DataStructure::AActor_DataStructure()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActor_DataStructure::BeginPlay()
{
	Super::BeginPlay();
	
	FString JoinedStr;

	/*
	for (FString& Str : StrArr)
	{
		JoinedStr += Str;
		JoinedStr += TEXT(" ");
	}
	*/
	/*
	for (int32 Index = 0; Index != StrArr.Num(); ++Index)
	{
		JoinedStr += StrArr[Index];
		JoinedStr += TEXT(" ");
	}
	*/
	/*
	//TArray<FString>::tIterator It;
	//for (auto It = StrArr.CreateConstIterator(); It; ++It)
	for (auto It = StrArr.CreateConstIterator(); It; ++It)
	{
		JoinedStr += *It;
		JoinedStr += TEXT(" ");
	}
	UKismetSystemLibrary::PrintString(GetWorld(), JoinedStr, true, true,
		FLinearColor::Blue, 4.0f);
	*/
	/*
	for (TObjectIterator<UStaticMeshComponent> ObjectItr; ObjectItr; ++ObjectItr)
	{
		UStaticMeshComponent* SMComp = *ObjectItr;
		UKismetSystemLibrary::PrintString(GetWorld(), SMComp->GetName(), true, true,
			FLinearColor::Blue, 4.0f);
	}
	*/
	/*
	for (FActorIterator ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AActor* actor_temp = *ActorItr;
		UKismetSystemLibrary::PrintString(GetWorld(), actor_temp->GetName(), true, true,
			FLinearColor::Blue, 4.0f);
	}
	*/

}

// Called every frame
void AActor_DataStructure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

