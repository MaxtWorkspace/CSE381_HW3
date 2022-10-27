// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ball.h"
#include "Components/CapsuleComponent.h"
#include "FPSModeBase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Wolfie.generated.h"

UCLASS()
class CSE381_HW1_API AWolfie : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay)
	ABall* ballInHand;

	UCapsuleComponent* collider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool IsBoss;

public:
	// Sets default values for this character's properties
	AWolfie();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Gun muzzle offset from the camera location.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

	UFUNCTION(BlueprintCallable)
	void Fire();

	void CatchBall(ABall* ball);

	// Function that is called when the projectile hits something.
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
