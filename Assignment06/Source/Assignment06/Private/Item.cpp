#include "Item.h"

AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	OnItemPickedUP();

	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	SetActorRotation(FRotator(0, 90, 0));
	SetActorScale3D(FVector(2.0f));
}

void AItem::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	if(!FMath::IsNearlyZero(RotationSpeed))
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * Deltatime, 0.0f));
}

void AItem::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}