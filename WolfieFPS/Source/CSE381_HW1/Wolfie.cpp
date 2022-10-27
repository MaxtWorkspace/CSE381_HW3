// Fill out your copyright notice in the Description page of Project Settings.


#include "Wolfie.h"

// Sets default values
AWolfie::AWolfie()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collider = FindComponentByClass<UCapsuleComponent>();
	check(collider != nullptr);
	collider->OnComponentHit.AddDynamic(this, &AWolfie::OnHit);
}

// Called when the game starts or when spawned
void AWolfie::BeginPlay()
{
	Super::BeginPlay();
	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Wolfie Started."));
}

// Called to bind functionality to input
void AWolfie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AWolfie::Fire()
{
	if (ballInHand) {
		ballInHand->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		FVector LaunchDirection = UKismetMathLibrary::GetDirectionUnitVector(GetTransform().GetLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
		LaunchDirection.Z = LaunchDirection.Z*2;
		ballInHand->FireInDirection(LaunchDirection);
		ballInHand->side = 2;
		ballInHand = nullptr;
	}
}

void AWolfie::CatchBall(ABall* ball) {
	// Attempt to catch a ball
	if (ballInHand == nullptr && !IsBoss) {
		// Get the camera transform.
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		// Transform MuzzleOffset from camera space to world space.
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		// Skew the aim to be slightly upwards.
		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;

		ball->ResetTransform(MuzzleLocation, MuzzleRotation.Quaternion());
		ball->side = 2;

		ballInHand = ball;
		ballInHand->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	}
	else {
		ball->Destroy();
	}
}

void AWolfie::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) {
	if (!OtherActor) return;

	ABall* ball = Cast<ABall>(OtherActor);
	if (ball) {
		if (ball->side == 1) {
			AFPSModeBase* gm = Cast<AFPSModeBase>(GetWorld()->GetAuthGameMode());
			gm->OnWolfieHit(IsBoss);
			ball->Destroy();
			Destroy();
			return;
		}

		CatchBall(ball);
	}
}
