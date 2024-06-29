// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealClass_240622GameMode.h"
#include "UnrealClass_240622PlayerController.h"
#include "UnrealClass_240622Character.h"
#include "UObject/ConstructorHelpers.h"

AUnrealClass_240622GameMode::AUnrealClass_240622GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AUnrealClass_240622PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}