// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.h"
#include "SpawnPoint.generated.h"

UCLASS()
class CSE381_HW1_API ASpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Projectile class to spawn.
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABall> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	float spawnTimer;

	float lastSpawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawn)
	int spawnCount;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
