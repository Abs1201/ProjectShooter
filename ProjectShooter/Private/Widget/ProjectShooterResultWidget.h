// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include <Components/GridPanel.h>

#include "ProjectShooterResultWidget.generated.h"



/**
 * 
 */
UCLASS()
class UProjectShooterResultWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	UFUNCTION(BlueprintCallable)
	void InitRankingCPP();



protected:

	
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UTextBlock> TextScore;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		TObjectPtr<UTextBlock> TextRanking;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		TObjectPtr<UGridPanel> RankingTable;

};
