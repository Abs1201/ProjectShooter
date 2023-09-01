// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectShooterGun.generated.h"

UCLASS()
class AProjectShooterGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectShooterGun();

	UFUNCTION(BlueprintCallable)
	void FireBulletCPP(UClass* BulletClass, FTransform Transform);

	UFUNCTION(BlueprintCallable)
	void RegisterNextFireCPP(float Duration);

	UFUNCTION(BlueprintCallable)
		void FireReleasedCPP();

	UFUNCTION(BlueprintCallable)
	bool IsFiringCPP() const;

	UFUNCTION(BlueprintCallable)
		void MakeRecoilCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BulletSpeedCPP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTimerHandle TimerFireCPP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFirePressedCPP;
};
