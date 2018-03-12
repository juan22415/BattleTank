// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	void AimTowardsCrosshair();

	bool GetSightRaycastHitLocation(FVector& HitLocation) const;

	bool GetlookVectorDirection(FVector LookDirection, FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& WoldDirection) const;

	UPROPERTY(EditAnyWhere)
	float CorssHairXLocation = 0.5;
	UPROPERTY(EditAnyWhere)
	float CorssHairYLocation = 0.3333;

private:
	UPROPERTY(EditAnyWhere)
	float LineTraceRange = 1000000.f;
	
};
