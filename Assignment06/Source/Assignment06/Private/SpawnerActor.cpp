#include "SpawnerActor.h"

ASpawnerActor::ASpawnerActor()
{

}

void ASpawnerActor::BeginPlay()
{
    Super::BeginPlay();

    if (!RotatingActorClass) return;

    TArray<FVector> AllPoints;

    for (int32 x = 0; x <= 600; x += 200)
    {
        for (int32 y = 700; y <= 1100; y += 200)
        {
            AllPoints.Add(FVector(x, y, FMath::RandRange(750.0f, 1000.0f)));
        }
    }

    for (int32 i = AllPoints.Num() - 1; i > 0; i--)
    {
        int32 j = FMath::RandRange(0, i);
        AllPoints.Swap(i, j);
    }


    for (int32 i = 0; i < FMath::RandRange(5, AllPoints.Num()); i++)
    {
        GetWorld()->SpawnActor<ARotatingActor>(
            RotatingActorClass,
            AllPoints[i],
            GetRandomRotate()
        );
    }
}

FRotator ASpawnerActor::GetRandomRotate()
{
    FRotator RandomRotation = FRotator(
        FMath::RandRange(0.0f, 360.0f),
        FMath::RandRange(0.0f, 360.0f),
        FMath::RandRange(0.0f, 360.0f)
    );

    return RandomRotation;
}