// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner_PowerUps.h"

// Sets default values
ASpawner_PowerUps::ASpawner_PowerUps()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPoint0 = CreateDefaultSubobject<USceneComponent>((TEXT("SpawnPoint0")));
	SpawnPoint0->SetupAttachment(RootComponent);
	SpawnPoint1 = CreateDefaultSubobject<USceneComponent>((TEXT("SpawnPoint1")));
	SpawnPoint1->SetupAttachment(RootComponent);
	SpawnPoint2 = CreateDefaultSubobject<USceneComponent>((TEXT("SpawnPoint2")));
	SpawnPoint2->SetupAttachment(RootComponent);
	SpawnPoint3 = CreateDefaultSubobject<USceneComponent>((TEXT("SpawnPoint3")));
	SpawnPoint3->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpawner_PowerUps::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnPoints.Empty();
	TArray<USceneComponent*> Components;
	GetComponents<USceneComponent>(Components);
	for (USceneComponent* Component : Components)
	{
		if (Component && Component->GetName().Contains(TEXT("SpawnPoint")))
		{
			SpawnPoints.Add(Component);
		}
	}

	SpawnPowerUp();
}

void ASpawner_PowerUps::SpawnPowerUp()
{
	if (PowerUpClass && !SpawnPoints.IsEmpty())
	{
		const int32 IndiceAleatorio = FMath::RandRange(0, SpawnPoints.Num() - 1);
		USceneComponent* SpawnPointElegido = SpawnPoints[IndiceAleatorio];

		if (SpawnPointElegido)
		{
			/*const FVector PosicionSpawn = SpawnPointElegido->GetComponentLocation();
			const FRotator RotacionSpawn = SpawnPointElegido->GetComponentRotation();

			GetWorld()->SpawnActor<APowerUp>(PowerUpClass, PosicionSpawn, RotacionSpawn);*/

			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			GetWorld()->SpawnActor<APowerUp>(PowerUpClass, SpawnPointElegido->GetComponentTransform(), SpawnParams);
		}

		GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawner_PowerUps::SpawnPowerUp, SpawnDelay, false);

	}
}

// Called every frame
void ASpawner_PowerUps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

