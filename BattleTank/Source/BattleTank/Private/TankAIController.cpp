// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayertank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not finding player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("player tank found: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetPlayertank();
	if (!PlayerTank) { return; }

	GetAIControlledTank()->AimAt(PlayerTank->GetActorLocation());
	

}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());


}

ATank* ATankAIController::GetPlayertank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn)
	{
		return nullptr;
	}

	return Cast<ATank>(PlayerPawn);
	
}

