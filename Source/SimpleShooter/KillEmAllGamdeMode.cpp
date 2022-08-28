// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGamdeMode.h"
#include "GameFramework/PlayerController.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"


void AKillEmAllGamdeMode::PawnKilled(APawn * PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    
    APlayerController * PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Kill Em All Game Mode: Found Player Controller"));

        EndGame(false);

        return;
    }

    // for loop for shooterAI in the world
    for (AShooterAIController * AIController: TActorRange<AShooterAIController>(GetWorld()))
    {
        if (!AIController->IsDead())
            return;
    }
        // is not dead? 
            // return early
    EndGame(true);
    // End Game (if no AI pawns are in the world)
}

void AKillEmAllGamdeMode::EndGame(bool bIsPlayerWinner)
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        // change first input from false -> Controller->GetPawn because we want the focus of the camera to be on the winner
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }   
}
