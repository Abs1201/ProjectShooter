// Fill out your copyright notice in the Description page of Project Settings.


#include "Cheat/ProjectShooterCheatManager.h"
#include <Settings/ProjectShooterUserSettings.h>

void UProjectShooterCheatManager::PSSetResolution(int32 Width, int32 Height)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		UserSettings->SetScreenResolution(FIntPoint(Width, Height));
		UserSettings->ApplySettings(false);
	}
}

void UProjectShooterCheatManager::PSSetWindowMode(int32 WindowMode)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		EWindowMode::Type NewWindowMode = (EWindowMode::Type)WindowMode;
		UserSettings->SetFullscreenMode(NewWindowMode);
		UserSettings->ApplySettings(false);
	}
}

void UProjectShooterCheatManager::PSSetMouseSensitivity(float Value)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		UserSettings->SetMouseSensitivity(Value);
		UserSettings->ApplySettings(false);
	}
}

void UProjectShooterCheatManager::PSSetBrightness(float Value)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		UserSettings->SetAutoExposureBrightness(Value);
		UserSettings->ApplySettings(false);
	}
}
