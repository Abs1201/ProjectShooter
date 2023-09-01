// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/ProjectShooterLaserPointer.h"

// Sets default values
AProjectShooterLaserPointer::AProjectShooterLaserPointer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float AProjectShooterLaserPointer::GetEndPointOfLaserCPP(const FVector Start, const FVector End) const
{
	float Distance = 0.0;
	FHitResult Result;
	if (GetWorld()->LineTraceSingleByChannel(Result, Start, End, ECollisionChannel::ECC_Visibility)) {
		Distance = Result.Distance;
	}
	else {
		Distance = (End - Start).Length();
	}
	return Distance;
}

// Called when the game starts or when spawned
void AProjectShooterLaserPointer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectShooterLaserPointer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

