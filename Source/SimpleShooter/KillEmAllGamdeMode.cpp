// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGamdeMode.h"
#include "GameFramework/PlayerController.h"


void AKillEmAllGamdeMode::PawnKilled(APawn * PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    
    APlayerController * PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Kill Em All Game Mode: Found Player Controller"));

        PlayerController->GameHasEnded(nullptr, false);
    }
}
