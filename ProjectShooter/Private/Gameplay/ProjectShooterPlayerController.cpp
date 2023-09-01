// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/ProjectShooterPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "ProjectShooterGameMode.h"
#include <Kismet/GameplayStatics.h>

void AProjectShooterPlayerController::OnEndGameCPP()
{
	UUserWidget* Widget = CreateWidget(this, ResultWidget);
	if (Widget) {
		Widget->AddToViewport();
	}
}

void AProjectShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem) {
		Subsystem->AddMappingContext(ProjectShooterInputMappingContext, 0);
	}

	UUserWidget* Widget = CreateWidget(this, GameplayWidget);
	if (Widget) {
		Widget->AddToViewport();
	}
	AProjectShooterGameMode* GameMode = Cast<AProjectShooterGameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode) {
		GameMode->OnEndGameCPP.AddUniqueDynamic(this, &AProjectShooterPlayerController::OnEndGameCPP);
	}
}
