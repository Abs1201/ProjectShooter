// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "ProjectShooterCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class UProjectShooterCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(exec)
		void PSSetResolution(int32 Width, int32 Height);

	UFUNCTION(exec)
	void PSSetWindowMode(int32 WindowMode);

	UFUNCTION(exec)
	void PSSetMouseSensitivity(float Value);

	UFUNCTION(exec)
	void PSSetBrightness(float Value);
};
