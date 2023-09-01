// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectShooterGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FProjectShooterGameModeOnEndGame, AProjectShooterGameMode, OnEndGameCPP);

/**
 *
 */

UENUM(BlueprintType)
enum class StateOfGameCPP : uint8
{
	Ready,
	Playing,
	Ended,
};

UCLASS()
class AProjectShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateRankingCPP();

	UFUNCTION(BlueprintCallable)
		StateOfGameCPP GetStateCPP() const;

	UFUNCTION(BlueprintCallable)
		FDateTime GetStartTimeCPP() const;

	UFUNCTION(BlueprintCallable)
	int32 GetRankingCPP() const;

	UFUNCTION(BlueprintCallable)
	TArray<float> GetRankingScoresCPP() const;

	UFUNCTION(BlueprintCallable)
		TArray<FString> GetRankingTimesCPP() const;

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FProjectShooterGameModeOnEndGame OnEndGameCPP;

protected:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		FDateTime StartTimeCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		FDateTime EndTimeCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		TArray<float> RankingScoresCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		TArray<FString> RankingTimesCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		int32 RankingCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	float ScoreCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		StateOfGameCPP StateCPP;
	

};
