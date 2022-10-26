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
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Player Hit! Remaining HP"));
	if (playerHP <= 0) {

	}
}

void AFPSModeBase::OnWolfieHit(bool isBoss) {
	score++;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Player Scored!"));
}