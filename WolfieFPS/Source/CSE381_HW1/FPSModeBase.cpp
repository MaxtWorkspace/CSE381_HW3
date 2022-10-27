// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSModeBase.h"

void AFPSModeBase::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));

	playerHP = 1;
	score = 0;
}

void AFPSModeBase::OnPlayerHit() {
	playerHP--;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Player Hit! Remaining HP"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Player Hit! Remaining HP: %u"), playerHP));
	if (playerHP != 1) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Player Dead"));
		// restart game
		AFPSHUD* a = Cast<AFPSHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		a->LoseGame();
	}
}

void AFPSModeBase::OnWolfieHit(bool isBoss) {
	score++;
	
	AFPSHUD* d = Cast<AFPSHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
    d->IncScore();
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Player Scored!"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Player Scored! Score: %u"), score));
	if (isBoss) {
		//end game
		AFPSHUD* a = Cast<AFPSHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		a->EndGame();
	}
}

int AFPSModeBase::GetScore() {
	return score;
}