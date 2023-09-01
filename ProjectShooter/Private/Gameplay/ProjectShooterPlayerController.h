// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <widget/projectshootergameplaywidget.h>
#include "inputmappingcontext.h"

#include "ProjectShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AProjectShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnEndGameCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr< UInputMappingContext> ProjectShooterInputMappingContext;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> GameplayWidget;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UUserWidget> ResultWidget;
};
