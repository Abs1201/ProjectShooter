// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <InputAction.h>
#include "ProjectShooterCharacter.generated.h"


UENUM(BlueprintType)
enum class StateOfCharacterCPP : uint8
{
	Idle,
	Aiming,
	Reloading,
	Swaping,
	Running,
};

UCLASS()
class AProjectShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AProjectShooterCharacter();

	UFUNCTION(BlueprintCallable)
	virtual float GetSpeedCPP() const;

	UFUNCTION(BlueprintCallable)
	virtual bool CanRunCPP() const;

	UFUNCTION(BlueprintCallable)
	virtual void TickRunCPP();

	UFUNCTION(BlueprintCallable)
	virtual void OnFootstepLeftCPP();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void TickBrightness();

	virtual void OnTriggerRun(const FInputActionValue& Value);
	virtual void OnTriggerTurnPitch(const FInputActionValue& Value);
	virtual void OnTriggerTurnYaw(const FInputActionValue& Value);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	StateOfCharacterCPP StateCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	bool IsRunPressedCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	float MoveForwardValueCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USoundBase> FootstepLeftSoundCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputAction> RunInputAction;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
		TObjectPtr<UInputAction> TurnPitchInputAction;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
		TObjectPtr<UInputAction> TurnYawInputAction;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
		TObjectPtr<UInputAction> JumpInputAction;


private:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> ShadowBodyCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UChildActorComponent> WeaponInBackCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> LowerBodyCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> CameraCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> FirstPersonCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UChildActorComponent> WeaponInHandCPP;



};
