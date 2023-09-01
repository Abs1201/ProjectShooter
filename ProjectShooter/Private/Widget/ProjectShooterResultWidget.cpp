// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/ProjectShooterResultWidget.h"
#include <Kismet/GameplayStatics.h>
#include <Gameplay/ProjectShooterGameMode.h>
#include <Blueprint/WidgetTree.h>
#include <Components/GridSlot.h>

void UProjectShooterResultWidget::NativeConstruct()
{
	InitRankingCPP();
}

void UProjectShooterResultWidget::InitRankingCPP()
{
	AProjectShooterGameMode* GameMode = Cast<AProjectShooterGameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode) {
		int32 Ranking = GameMode->GetRankingCPP();
		TArray<float> Scores = GameMode->GetRankingScoresCPP();
		TArray<FString> Times = GameMode->GetRankingTimesCPP();

		{
			FString Text = TEXT("Your ranking = #") + FString::FromInt(Ranking);
			TextRanking->SetText(FText::FromString(Text));
		}

		for (int32 Index = 0; Index < Scores.Num(); ++Index) {
			int32 Row = Index + 1;

			UTextBlock* Rank = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
			if (Rank) {
				Rank->SetText(FText::AsNumber(Row));
				UGridSlot* ChildSlot = RankingTable->AddChildToGrid(Rank, Row, 0);
				ChildSlot->SetNudge(FVector2D(0.0, 20.0 * Row));
			}

			UTextBlock* Score = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
			if (Score) {
				Score->SetText(FText::AsNumber(Scores[Index]));
				UGridSlot* ChildSlot = RankingTable->AddChildToGrid(Score, Row, 1);
				ChildSlot->SetNudge(FVector2D(200.0, 20.0 * Row));
			}

			UTextBlock* Time = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
			if (Time) {
				Time->SetText(FText::FromString(Times[Index]));
				UGridSlot* ChildSlot = RankingTable->AddChildToGrid(Time, Row, 2);
				ChildSlot->SetNudge(FVector2D(400.0, 20.0 * Row));
			}
		}
	}
}
