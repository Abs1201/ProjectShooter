// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ProjectShooterSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class UProjectShooterSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TArray<float> ScoresCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TArray<FString> TimesCPP;


	
};
