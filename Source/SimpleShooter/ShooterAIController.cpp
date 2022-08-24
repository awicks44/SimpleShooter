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

        APawn *GetPlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        APawn *AIPawn = GetPawn();

        UBlackboardComponent *BB = GetBlackboardComponent();

        if (BB)
        {
            BB->SetValueAsVector(TEXT("PlayerLocation"), GetPlayerPawn->GetActorLocation());
            BB->SetValueAsVector(TEXT("StartLocation"), AIPawn->GetActorLocation());
        }
      
       
    }
}

void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    
}
