// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h" 
#include "CanvasItem.h"
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class CSE381_HW1_API AFPSHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	// This will be drawn at the center of the screen.
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* CrosshairTexture;

	UPROPERTY(EditDefaultsOnly)
	int Score;

	UPROPERTY(EditDefaultsOnly)
	FText GameText;

public:
	// Primary draw call for the HUD.
	virtual void DrawHUD() override;
	void IncScore();
	void EndGame();
	void LoseGame();
};
