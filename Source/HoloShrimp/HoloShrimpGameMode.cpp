// Copyright Epic Games, Inc. All Rights Reserved.

#include "HoloShrimpGameMode.h"
#include "HoloShrimpPlayerController.h"
#include "HoloShrimpCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHoloShrimpGameMode::AHoloShrimpGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHoloShrimpPlayerController::StaticClass();

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