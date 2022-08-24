// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);

        PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        APawn *AIPawn = GetPawn();

        BB = GetBlackboardComponent();

        if (BB)
        {
            BB->SetValueAsVector(TEXT("StartLocation"), AIPawn->GetActorLocation());
        }
    }
}

void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);    

    if (PlayerPawn == nullptr || BB == nullptr) return;

    if (LineOfSightTo(PlayerPawn))
    {
        BB->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        BB->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
    }
    else 
    {
        BB->ClearValue(TEXT("PlayerLocation"));
    }
}
