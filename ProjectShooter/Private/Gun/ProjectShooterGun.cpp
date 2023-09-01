// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/ProjectShooterGun.h"
#include "ProjectShooterBullet.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include <Gameplay/ProjectShooterCharacter.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values
AProjectShooterGun::AProjectShooterGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AProjectShooterGun::FireBulletCPP(UClass* BulletClass, FTransform Transform)
{
	AProjectShooterBullet* Bullet = Cast<AProjectShooterBullet>(GetWorld()->SpawnActor(BulletClass, &Transform));
	if (Bullet) {
		Bullet->SetSpeedCPP(BulletSpeedCPP);
	}
}

void AProjectShooterGun::RegisterNextFireCPP(float Duration)
{
	TimerFireCPP = UKismetSystemLibrary::K2_SetTimer(this, TEXT("Fire"), Duration, false);
}

void AProjectShooterGun::FireReleasedCPP()
{
	IsFirePressedCPP = false;
	GetWorld()->GetTimerManager().ClearTimer(TimerFireCPP);
}

bool AProjectShooterGun::IsFiringCPP() const
{
	return IsFirePressedCPP && GetWorld()->GetTimerManager().IsTimerActive(TimerFireCPP);
}

void AProjectShooterGun::MakeRecoilCPP()
{
	AProjectShooterCharacter* Character = Cast<AProjectShooterCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (Character) {
		float Pitch = UKismetMathLibrary::RandomFloatInRange(-0.1, -0.1);
		Character->APawn::AddControllerPitchInput(Pitch);

		float Yaw = UKismetMathLibrary::RandomFloatInRange(-0.1, -0.1);
		Character->APawn::AddControllerYawInput(Yaw);
	}
}

// Called when the game starts or when spawned
void AProjectShooterGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectShooterGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

