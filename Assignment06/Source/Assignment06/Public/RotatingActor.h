#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class ASSIGNMENT06_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};