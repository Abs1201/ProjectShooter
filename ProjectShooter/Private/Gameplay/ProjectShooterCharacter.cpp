// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/ProjectShooterCharacter.h"
#include <GameFramework/CharacterMovementComponent.h>
#include <Kismet/GameplayStatics.h>
#include <EnhancedInputComponent.h>
#include <Settings/ProjectShooterUserSettings.h>

// Sets default values
AProjectShooterCharacter::AProjectShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShadowBodyCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ShadowBodyCPP"));
	if (ShadowBodyCPP) {
		ShadowBodyCPP->SetupAttachment(RootComponent);
		WeaponInBackCPP = CreateDefaultSubobject<UChildActorComponent>(TEXT("weaponInBackCPP"));
		if (WeaponInBackCPP) {
			WeaponInBackCPP->SetupAttachment(ShadowBodyCPP);
		}
	}

	LowerBodyCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LowerBodyCPP"));
	LowerBodyCPP->SetupAttachment(RootComponent);

	CameraCPP = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraCPP"));
	if (CameraCPP) {
		CameraCPP->SetupAttachment(RootComponent);
		FirstPersonCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonCPP"));
		if (FirstPersonCPP) {
			FirstPersonCPP->SetupAttachment(CameraCPP);
			WeaponInHandCPP = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponInHandCPP"));
			if (WeaponInHandCPP) {
				WeaponInHandCPP->SetupAttachment(FirstPersonCPP);
			}
		}
	}
}

// Called when the game starts or when spawned
void AProjectShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectShooterCharacter::TickBrightness()
{
	float Brightness = 0.0;
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		Brightness = UserSettings->GetAutoExposureBrightness();
	}

	if (CameraCPP) {
		FPostProcessSettings Settings = CameraCPP->PostProcessSettings;
		Settings.AutoExposureMinBrightness = Brightness;
		Settings.AutoExposureMaxBrightness = Brightness;
		CameraCPP->PostProcessSettings = Settings;

	}
}

void AProjectShooterCharacter::OnTriggerRun(const FInputActionValue& Value)
{
	IsRunPressedCPP = Value.Get<bool>();
}

void AProjectShooterCharacter::OnTriggerTurnPitch(const FInputActionValue& Value)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		float Pitch = UserSettings->GetMouseSensitivity()* Value.Get<float>();
		AddControllerPitchInput(Pitch);
	}
}

void AProjectShooterCharacter::OnTriggerTurnYaw(const FInputActionValue& Value)
{
	UProjectShooterUserSettings* UserSettings = Cast<UProjectShooterUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		float Yaw = UserSettings->GetMouseSensitivity() * Value.Get<float>();
		AddControllerYawInput(Yaw);
	}
}

// Called every frame
void AProjectShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TickBrightness();

}

// Called to bind functionality to input
void AProjectShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Run
		EnhancedInputComponent->BindAction(RunInputAction, ETriggerEvent::Triggered, this, &AProjectShooterCharacter::OnTriggerRun);
		//TurnPitch
		EnhancedInputComponent->BindAction(TurnPitchInputAction, ETriggerEvent::Triggered, this, &AProjectShooterCharacter::OnTriggerTurnPitch);
		//TurnYaw
		EnhancedInputComponent->BindAction(TurnYawInputAction, ETriggerEvent::Triggered, this, &AProjectShooterCharacter::OnTriggerTurnYaw);
		//Jump
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &AProjectShooterCharacter::OnTriggerJump);
	}

}

float AProjectShooterCharacter::GetSpeedCPP() const
{
	return GetVelocity().Length();
}

bool AProjectShooterCharacter::CanRunCPP() const
{
	return (MoveForwardValueCPP > 0.0) && IsRunPressedCPP;
}

void AProjectShooterCharacter::TickRunCPP()
{
	if (CanRunCPP()) {
		switch (StateCPP) {
		case StateOfCharacterCPP::Idle:
			StateCPP = StateOfCharacterCPP::Running;
			GetCharacterMovement()->MaxWalkSpeed *= 2.0;
		}
	}
	else {
		switch (StateCPP) {
		case StateOfCharacterCPP::Running:
			StateCPP = StateOfCharacterCPP::Idle;
			GetCharacterMovement()->MaxWalkSpeed *= 0.5;
		}
	}
}

void AProjectShooterCharacter::OnFootstepLeftCPP()
{
	UGameplayStatics::PlaySoundAtLocation(this, FootstepLeftSoundCPP, LowerBodyCPP->GetSocketLocation("foot_l"));
}

