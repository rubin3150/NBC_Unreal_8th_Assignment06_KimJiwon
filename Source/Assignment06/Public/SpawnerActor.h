#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.h"
#include "SpawnerActor.generated.h"

UCLASS()
class ASSIGNMENT06_API ASpawnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnerActor();

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<ARotatingActor> RotatingActorClass;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 SpawnCount = 12;

	FRotator GetRandomRotate();

protected:
	virtual void BeginPlay() override;
};