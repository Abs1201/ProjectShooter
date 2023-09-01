// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectShooterLaserPointer.generated.h"

UCLASS()
class AProjectShooterLaserPointer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectShooterLaserPointer();

	UFUNCTION(BlueprintCallable)
		float GetEndPointOfLaserCPP(const FVector Start, const FVector End) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
