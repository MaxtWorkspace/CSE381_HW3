// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "FPSHUD.h"
#include "FPSModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CSE381_HW1_API AFPSModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;

	int playerHP;
	int score;

public:
	void OnPlayerHit();

	void OnWolfieHit(bool isBoss);

	int GetScore();
};
