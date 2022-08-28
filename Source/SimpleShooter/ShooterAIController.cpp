// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"


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
}

bool AShooterAIController::IsDead() const
{
    // we check to see if the pawn controlling the AI is a shooter character and we pass on the IsDead function
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if (ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }

    // otherwise, we just confirm the pawn is dead by passing true. This could happen because the pawn controller 'detaches' from it's AI when it dies
    return true;
}
