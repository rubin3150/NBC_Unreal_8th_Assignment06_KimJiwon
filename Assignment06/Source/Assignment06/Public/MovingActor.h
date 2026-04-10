#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class ASSIGNMENT06_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();
	FVector StartLocation;
	FTimerHandle TimerHandle;
	float ElapsedTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	bool IsDestroy;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void OnDisappearTimer();
};