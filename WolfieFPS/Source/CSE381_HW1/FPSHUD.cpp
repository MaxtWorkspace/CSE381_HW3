// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSHUD.h"
#if WITH_EDITOR
#define LOCTEXT_NAMESPACE "UMG"

void AFPSHUD::DrawHUD()
{
    Super::DrawHUD();

    if (CrosshairTexture)
    {
        // Find the center of our canvas.
        FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

        // Offset by half of the texture's dimensions so that the center of the texture aligns with the center of the Canvas.
        FVector2D CrossHairDrawPosition(Center.X - (CrosshairTexture->GetSurfaceWidth() * 0.5f), Center.Y - (CrosshairTexture->GetSurfaceHeight() * 0.5f));

        // Draw the crosshair at the centerpoint.
        FCanvasTileItem TileItem(CrossHairDrawPosition, CrosshairTexture->Resource, FLinearColor::White);
        TileItem.BlendMode = SE_BLEND_Translucent;
        Canvas->DrawItem(TileItem);
    }

    //Score = FPSModeBase->score;
    GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, FString::Printf(TEXT("%u"), Score));


    // Find the center of our canvas.
    FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

    // Offset by half of the texture's dimensions so that the center of the texture aligns with the center of the Canvas.
    FVector2D ScoreDrawPosition(Center.X + 500, Center.Y);

    //FCanvasTextItem TextItem(ScoreDrawPosition, FText("Score: "), GEngine->GetSmallFont(), FLinearColor::White);
    //TextItem.BlendMode = SE_BLEND_Translucent;
    //TextItem.Scale.Set(1.0f, 1.0f);
    //Canvas->DrawItem(TextItem);
    //AFPSModeBase obj;
    //Score = obj.GetScore();
    // Create a new FCanvasTextItem instance to contain the text.
    FCanvasTextItem TextItem(ScoreDrawPosition, FText(), GEngine->GetLargeFont(), FLinearColor::Green);
    // Add the text into the FCanvasTextItem.
    TextItem.Text = FText::Format(LOCTEXT("SnippetHeader", "Wolfies Remaining: {0}"), 6-Score);
    TextItem.Scale.Set(3.0f, 3.0f);
    // Draw the text to the screen with FCanvas::DrawItem.
    Canvas->DrawItem(TextItem, 100.0f, 50.0f);


    FVector2D ScoreDrawPosition1(Center.X+1000, Center.Y+1000);
    FCanvasTextItem TextItem2(ScoreDrawPosition1, FText(), GEngine->GetLargeFont(), FLinearColor::Green);
    // Add the text into the FCanvasTextItem.
    TextItem2.Text = GameText;
    TextItem2.Scale.Set(3.0f, 3.0f);
    // Draw the text to the screen with FCanvas::DrawItem.
    Canvas->DrawItem(TextItem2, Center.X - 100.0f, Center.Y - 50.0f);
}

void AFPSHUD::IncScore() {
    Score += 1;
}

void AFPSHUD::EndGame() {
    GameText = FText::Format(LOCTEXT("SnippetHeader", "Game Over! You Win! \n Score: {0}"), Score);
    Score = 0;
}

void AFPSHUD::LoseGame() {
    GameText = FText::Format(LOCTEXT("SnippetHeader", "Game Over! You Lost! \n Score: {0}"), Score);
    Score = 0;
}


#undef LOCTEXT_NAMESPACE
#endif
