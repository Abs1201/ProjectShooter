// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/ProjectShooterUserSettings.h"

float UProjectShooterUserSettings::GetMouseSensitivity() const
{
	return MouseSensitivity;
}

void UProjectShooterUserSettings::SetMouseSensitivity(float Value)
{
	MouseSensitivity = Value;
}

float UProjectShooterUserSettings::GetAutoExposureBrightness() const
{
	return AutoExposureBrightness;
}

void UProjectShooterUserSettings::SetAutoExposureBrightness(float Value)
{
	AutoExposureBrightness = Value;
}

void UProjectShooterUserSettings::SetToDefaults()
{
	Super::SetToDefaults();
	MouseSensitivity = 1.0;
	AutoExposureBrightness = 0.0;
}
