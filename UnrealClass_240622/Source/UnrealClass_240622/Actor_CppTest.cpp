// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor_CppTest.h"
#include "UObject/ConstructorHelpers.h"
#include "Character_CppTest.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AActor_CppTest::AActor_CppTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ����Ʈ ������Ʈ
	Shape = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyShape"));
	RootComponent = Shape;

	Shape_child1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyShape2"));
	Shape_child1->SetupAttachment(Shape);
	Shape_child1->RegisterComponent();

	// Ŭ���� ���� ����
	myPawnClass = APawn::StaticClass();

	// ���� ���۷���
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM01(TEXT("StaticMesh'/Game/ZombieSurvival/Assets/MyCube.MyCube'"));

	if (SM01.Succeeded()) {
		myStaticMesh = SM01.Object;
		Shape_child1->SetStaticMesh(myStaticMesh);
		UE_LOG(LogTemp, Log, TEXT("Success"));
	}
	else {
		UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Failed"), true, true,
			FLinearColor::Blue, 4.0f);
		UE_LOG(LogTemp, Log, TEXT("Failed"));
	}

}

// Called when the game starts or when spawned
void AActor_CppTest::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("BeginPlay"), true, true, 
		FLinearColor::Blue, 4.0f);
	UE_LOG(LogTemp, Log, TEXT("BeginPlay"));

	Shape_child2 = NewObject<UStaticMeshComponent>(this, FName("Shape_dynamic"));
	Shape_child2->ReregisterComponent();
	Shape_child2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Shape_child2->SetRelativeLocation(FVector(300, 300, 300));
	Shape_child2->SetStaticMesh(myStaticMesh);

	// Ÿ�̸� �۵�
	GetWorldTimerManager().SetTimer(Timer_Test, this, &AActor_CppTest::TimerTest, 3.0f, false);

	// �̺�Ʈ ���ε�
	ACharacter_CppTest* Actor_CppTest_Ref = Cast<ACharacter_CppTest>(UGameplayStatics::GetPlayerPawn(this, 0));
	//IsValid(Actor_CppTest_Ref);
	if (Actor_CppTest_Ref != nullptr)
	{
		Actor_CppTest_Ref->SomeEvent.BindUFunction(this, FName("Receive_SomeEvent"));
		Actor_CppTest_Ref->SomeEvent_OneParam.BindUFunction(this, FName("Receive_SomeEvent_OneParam"));
		Actor_CppTest_Ref->SomeEvent_Multi.AddUFunction(this, FName("Receive_SomeEvent_Multi1"));
		Actor_CppTest_Ref->SomeEvent_Multi.AddUFunction(this, FName("Receive_SomeEvent_Multi2"));
	}

}

void AActor_CppTest::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	// ��� �ۼ�
}

// Called every frame
void AActor_CppTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActor_CppTest::myFirstFunction()
{
}

void AActor_CppTest::TimerTest()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Timer Activated!"), true, true,
		FLinearColor::Blue, 4.0f);
}

void AActor_CppTest::Receive_SomeEvent()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Receive SomeEvent"), true, true,
		FLinearColor::Blue, 4.0f);
}

void AActor_CppTest::Receive_SomeEvent_OneParam(int val)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Receive SomeEvent_OneParam"), true, true,
		FLinearColor::Blue, 4.0f);
}

void AActor_CppTest::Receive_SomeEvent_Multi1()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Receive SomeEvent_Multi"), true, true,
		FLinearColor::Blue, 4.0f);
}

void AActor_CppTest::Receive_SomeEvent_Multi2()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Receive SomeEvent_Multi"), true, true,
		FLinearColor::Blue, 4.0f);
}

