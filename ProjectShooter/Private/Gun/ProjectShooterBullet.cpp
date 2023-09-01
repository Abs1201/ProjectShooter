// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/ProjectShooterBullet.h"

// Sets default values
AProjectShooterBullet::AProjectShooterBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletCPP = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletCPP"));
	if (BulletCPP) {
		RootComponent = BulletCPP;
	}

}

void AProjectShooterBullet::SetSpeedCPP(float Value)
{
	SpeedCPP = Value;
}

// Called when the game starts or when spawned
void AProjectShooterBullet::BeginPlay()
{
	Super::BeginPlay();
	
	if (BulletCPP) {
		BulletCPP->OnComponentHit.AddUniqueDynamic(this, &AProjectShooterBullet::OnHitCallback);
	}
}

void AProjectShooterBullet::OnHitCallback(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}

// Called every frame
void AProjectShooterBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

