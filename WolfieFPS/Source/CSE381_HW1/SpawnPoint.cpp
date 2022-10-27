// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPoint.h"

// Sets default values
ASpawnPoint::ASpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	lastSpawnTimer = 0.0f;
}

// Called when the game starts or when spawned
void ASpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	lastSpawnTimer += DeltaTime;
	
	if (lastSpawnTimer >= spawnTimer) {
		FVector location;
		FRotator rotation;
		GetActorEyesViewPoint(location, rotation);

		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			// Spawn the projectile at the spawn point.
			for (int i = 0; i < spawnCount; i++) {
				ABall* ball = World->SpawnActor<ABall>(ProjectileClass, location, rotation, SpawnParams);
				FVector dir(FMath::RandRange(-0.1f, 0.1f), FMath::RandRange(-0.1f, 0.1f), FMath::RandRange(0.0f, 0.0f));
				ball->FireInDirection(dir);
			}
		}

		lastSpawnTimer = 0.0f;
	}
}

