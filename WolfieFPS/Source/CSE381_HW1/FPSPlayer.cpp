// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayer.h"

// Sets default values
AFPSPlayer::AFPSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a first person camera component.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	check(FPSCameraComponent != nullptr);

	// Attach the camera component to our capsule component.
	FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
	
	// Position the camera slightly above the eyes.
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, BaseEyeHeight));

	// Enable the pawn to control camera rotation.
	FPSCameraComponent->bUsePawnControlRotation = true;

	// Create a first person mesh component for the owning player.
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	check(FPSMesh != nullptr);

	// Only the owning player sees this mesh.
	FPSMesh->SetOnlyOwnerSee(true);

	// Attach the FPS mesh to the FPS camera.
	FPSMesh->SetupAttachment(FPSCameraComponent);

	// Disable some environmental shadows to preserve the illusion of having a single mesh.
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	collider = FindComponentByClass<UCapsuleComponent>();
	check(collider != nullptr);
	collider->OnComponentHit.AddDynamic(this, &AFPSPlayer::OnHit);
}

// Called when the game starts or when spawned
void AFPSPlayer::BeginPlay()
{
	Super::BeginPlay();

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("FPS Player Started."));
	
}

// Called every frame
void AFPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Move key binding
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSPlayer::MoveRight);
	//Turn key binding
	PlayerInputComponent->BindAxis("Turn", this, &AFPSPlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSPlayer::AddControllerPitchInput);
	//jump key binding
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSPlayer::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSPlayer::StopJump);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSPlayer::Fire);
}

void AFPSPlayer::MoveForward(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AFPSPlayer::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AFPSPlayer::StartJump()
{
	bPressedJump = true;
}

void AFPSPlayer::StopJump()
{
	bPressedJump = false;
}

void AFPSPlayer::Fire()
{
	if (ballInHand) {
		ballInHand->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		// Get the camera transform.
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);
		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;
		FVector LaunchDirection = MuzzleRotation.Vector();
		ballInHand->FireInDirection(LaunchDirection);
		ballInHand = nullptr;
	}
}

void AFPSPlayer::CatchBall(ABall* ball) {
	// Attempt to catch a ball
	if (ballInHand == nullptr) {
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
		ball->side = 1;

		ballInHand = ball;
		ballInHand->AttachToComponent(FPSCameraComponent, FAttachmentTransformRules::KeepWorldTransform);
	}
	else {
		//ball->Destroy();
	}
}

void AFPSPlayer::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) {
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("a"));
	if (!OtherActor) return;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("b"));

	ABall* ball = Cast<ABall>(OtherActor);
	if (ball) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("obj is ball"));
		if (ball->side == 2) {
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("ball is 2"));
			AFPSModeBase* gm = Cast<AFPSModeBase>(GetWorld()->GetAuthGameMode());
			gm->OnPlayerHit();
			ball->Destroy();
		}
		else {
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("ball is not 2"));
			CatchBall(ball);
		}
	}
}