// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/ProjectShooterGameplayWidget.h"
#include <Gameplay/ProjectShooterGameMode.h>
#include <Kismet/GameplayStatics.h>

void UProjectShooterGameplayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//TextTime->SetText(FText::FromString(TEXT("TextTime")));
}

void UProjectShooterGameplayWidget::TickTimeCPP()
{
	AProjectShooterGameMode* GameMode = Cast<AProjectShooterGameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode) {
		StateOfGameCPP State = GameMode->GetStateCPP();
		FDateTime StartTime = GameMode->GetStartTimeCPP();
		FDateTime Now = FDateTime::Now();
		FTimespan Delta = Now - StartTime;

		switch (State) {
		case StateOfGameCPP::Ready:
			TextTime->SetText(FText::FromString(TEXT("")));
			break;

		case StateOfGameCPP::Playing:
			FString Minutes = FString::FromInt(Delta.GetMinutes());
			FString Seconds = FString::FromInt(Delta.GetSeconds());
			FString Milliseconds = FString::FromInt(Delta.GetFractionMilli());
			FString Text = TEXT("Stopwatch > ") + Minutes + TEXT(":") + Seconds + TEXT(".") + Milliseconds;
			TextTime->SetText(FText::FromString(Text));
			break;
		}

	}
}
