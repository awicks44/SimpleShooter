// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
    HUDScreen = CreateWidget(this, HUDScreenClass);

    if (HUDScreen != nullptr)
    {
        HUDScreen->AddToViewport();
    }
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    HUDScreen->RemoveFromViewport();

    if (bIsWinner)
    {
        UUserWidget * LoseScreen = CreateWidget(this, WinScreenClass);

        if (LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }
    else 
    {
        UUserWidget * LoseScreen = CreateWidget(this, LoseScreenClass);

        if (LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }

    

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}


