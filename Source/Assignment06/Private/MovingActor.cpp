#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	MoveSpeed = FMath::RandRange(1, 5);

	if (IsDestroy)
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMovingActor::OnDisappearTimer, 3.0f, false);
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedTime += DeltaTime * MoveSpeed;
	if (ElapsedTime > 2 * PI)
		ElapsedTime -= 2 * PI;
	FVector NewLocation = StartLocation + GetActorForwardVector() * FMath::Sin(ElapsedTime) * MaxRange;
	SetActorLocation(NewLocation);
}

void AMovingActor::OnDisappearTimer()
{
	Destroy();
}

void AMovingActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}