// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/ProjectShooterUserSettingsWidget.h"
#include <Settings/ProjectShooterUserSettings.h>

void UProjectShooterUserSettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitComponents();
	BindEvents();
}

void UProjectShooterUserSettingsWidget::InitComponents()
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		FIntPoint Resolution = UserSettings->GetScreenResolution();
		EditWidth->SetText(FText::AsNumber(Resolution.X));
		EditHeight->SetText(FText::AsNumber(Resolution.Y));

		EWindowMode::Type WindowMode = UserSettings->GetFullscreenMode();
		switch (WindowMode) {
		case EWindowMode::Fullscreen:
			ButtonFullscreen->SetIsEnabled(false);
			break;

		case EWindowMode::WindowedFullscreen:
			ButtonBorderless->SetIsEnabled(false);
			break;

		case EWindowMode::Windowed:
			ButtonWindowed->SetIsEnabled(false);
			break;
		}

		float MouseSensitivity = UserSettings->GetMouseSensitivity();
		SliderMouseSensitivity->SetValue(MouseSensitivity);
		TextMouseSensitivity->SetText(FText::AsNumber(MouseSensitivity));

		float AutoExposureBrightness = UserSettings->GetAutoExposureBrightness();
		float Brightness = (AutoExposureBrightness * -1.0) + 5.0;
		SliderBrightness->SetValue(Brightness);
		TextBrightness->SetText(FText::AsNumber(Brightness));
	}
}

void UProjectShooterUserSettingsWidget::BindEvents()
{
	EditWidth->OnTextChanged.AddUniqueDynamic(this, &UProjectShooterUserSettingsWidget::OnWidthChanged);
	EditHeight->OnTextChanged.AddUniqueDynamic(this, &UProjectShooterUserSettingsWidget::OnHeightChanged);
	ButtonFullscreen->OnClicked.AddUniqueDynamic(this, &UProjectShooterUserSettingsWidget::OnFullscreenClicked);
	ButtonBorderless->OnClicked.AddUniqueDynamic(this, &UProjectShooterUserSettingsWidget::OnBorderlessClicked);
	ButtonWindowed->OnClicked.AddUniqueDynamic(this, &UProjectShooterUserSettingsWidget::OnWindowedClicked);
	SliderMouseSensitivity->OnValueChanged.AddUniqueDynamic(this, &UProjectShooterUserSettingsWidget::OnMouseSensitivityChanged);
	SliderBrightness->OnValueChanged.AddUniqueDynamic(this, &UProjectShooterUserSettingsWidget::OnBrightnessChanged);
	ButtonExit->OnClicked.AddUniqueDynamic(this, &UProjectShooterUserSettingsWidget::OnExitClicked);
}

void UProjectShooterUserSettingsWidget::OnWidthChanged(const FText& Text)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		if (Text.IsNumeric()) {
			FString String = Text.ToString();
			FIntPoint Resolution = UserSettings->GetScreenResolution();
			int32 Width = FCString::Atoi(*String);
			int32 Height = Resolution.Y;
			if ((Width >= 720) && (Height >= 480)) {
				UserSettings->SetScreenResolution(FIntPoint(Width, Height));
				UserSettings->ApplySettings(false);
			}
			
		}
	}
}

void UProjectShooterUserSettingsWidget::OnHeightChanged(const FText& Text)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		if (Text.IsNumeric()) {
			FString String = Text.ToString();
			FIntPoint Resolution = UserSettings->GetScreenResolution();
			int32 Width = Resolution.X;
			int32 Height = FCString::Atoi(*String); 
			if ((Width >= 720) && (Height >= 480)) {
				UserSettings->SetScreenResolution(FIntPoint(Width, Height));
				UserSettings->ApplySettings(false);
			}
		}
	}
}

void UProjectShooterUserSettingsWidget::OnFullscreenClicked()
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		UserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		UserSettings->ApplySettings(false);

		ButtonFullscreen->SetIsEnabled(false);
		ButtonBorderless->SetIsEnabled(true);
		ButtonWindowed->SetIsEnabled(true);
	}
}

void UProjectShooterUserSettingsWidget::OnBorderlessClicked()
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		UserSettings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
		UserSettings->ApplySettings(false);

		ButtonFullscreen->SetIsEnabled(true);
		ButtonBorderless->SetIsEnabled(false);
		ButtonWindowed->SetIsEnabled(true);
	}
}

void UProjectShooterUserSettingsWidget::OnWindowedClicked()
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		UserSettings->SetFullscreenMode(EWindowMode::Windowed);
		UserSettings->ApplySettings(false);

		ButtonFullscreen->SetIsEnabled(true);
		ButtonBorderless->SetIsEnabled(true);
		ButtonWindowed->SetIsEnabled(false);
	}
}

void UProjectShooterUserSettingsWidget::OnMouseSensitivityChanged(float Value)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {

		UserSettings->SetMouseSensitivity(Value);
		UserSettings->ApplySettings(false);

		
		TextMouseSensitivity->SetText(FText::AsNumber(Value));
	}
}

void UProjectShooterUserSettingsWidget::OnBrightnessChanged(float Value)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {

		float AutoExposureBrightness = (Value - 5.0) * -1.0;

		UserSettings->SetAutoExposureBrightness(AutoExposureBrightness);
		UserSettings->ApplySettings(false);

		TextBrightness->SetText(FText::AsNumber(Value));
	}
}

void UProjectShooterUserSettingsWidget::OnExitClicked()
{
	RemoveFromParent();
}
