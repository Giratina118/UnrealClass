// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "kismet/kismetSystemLibrary.h"
#include "TimerManager.h"

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

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Shape;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Shape_child1;

	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* Shape_child2;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int> myIntArray;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMesh* myStaticMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<APawn> myPawnClass;

	FTimerHandle Timer_Test;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void myFirstFunction();

	void TimerTest();

	UFUNCTION()
	void Receive_SomeEvent();
	UFUNCTION()
	void Receive_SomeEvent_OneParam(int val);
	UFUNCTION()
	void Receive_SomeEvent_Multi1();
	UFUNCTION()
	void Receive_SomeEvent_Multi2();
};
