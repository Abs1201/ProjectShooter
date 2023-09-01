// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/ProjectShooterGameMode.h"

void AProjectShooterGameMode::UpdateRankingCPP()
{
	int32 RankingIndex = 0;
	for (int i = 0; i < RankingScoresCPP.Num(); i++) {
		if (RankingScoresCPP[i] >= ScoreCPP)
			RankingIndex++;
		else break;
	}
	RankingCPP = RankingIndex + 1;
	RankingScoresCPP.Insert(ScoreCPP, RankingIndex);
	RankingTimesCPP.Insert(EndTimeCPP.ToString(), RankingIndex);
	if (RankingScoresCPP.Num() > 10) {
		RankingScoresCPP.RemoveAt(RankingScoresCPP.Num() - 1);
		RankingTimesCPP.RemoveAt(RankingTimesCPP.Num() - 1);
	}
}

StateOfGameCPP AProjectShooterGameMode::GetStateCPP() const
{
	return StateCPP;
}

FDateTime AProjectShooterGameMode::GetStartTimeCPP() const
{
	return StartTimeCPP;
}

int32 AProjectShooterGameMode::GetRankingCPP() const
{
	return RankingCPP;
}

TArray<float> AProjectShooterGameMode::GetRankingScoresCPP() const
{
	return RankingScoresCPP;
}

TArray<FString> AProjectShooterGameMode::GetRankingTimesCPP() const
{
	return RankingTimesCPP;
}
