// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"



ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController discovered Player Tank: %s"), *(PlayerTank->GetName()));
		return PlayerTank;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController coudl not find Player Tank"));
		return nullptr;
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControllerTank = GetControlledTank();

	if (!ControllerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControllerTank->GetName()) );
	}

	GetPlayerTank();

}

