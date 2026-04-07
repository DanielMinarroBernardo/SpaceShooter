// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
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
	SpawnPoint4 = CreateDefaultSubobject<USceneComponent>((TEXT("SpawnPoint4")));
	SpawnPoint4->SetupAttachment(RootComponent);
	SpawnPoint5 = CreateDefaultSubobject<USceneComponent>((TEXT("SpawnPoint5")));
	SpawnPoint5->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
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

	if (WhatDoISpawn == "Enemy") {
		SpawnEnemy();
	}
	if (WhatDoISpawn == "PowerUp") {
		SpawnPowerUp();
	}
}

void ASpawner::SpawnPowerUp()
{
	if (PowerUpClass && !SpawnPoints.IsEmpty())
	{
		const int32 IndiceAleatorio = FMath::RandRange(0, SpawnPoints.Num() - 1);
		USceneComponent* SpawnPointElegido = SpawnPoints[IndiceAleatorio];

		if (SpawnPointElegido)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			GetWorld()->SpawnActor<APowerUp>(PowerUpClass, SpawnPointElegido->GetComponentTransform(), SpawnParams);
		}

		GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawner::SpawnPowerUp, SpawnDelay, false);

	}
}
void ASpawner::SpawnEnemy()
{
	if (EnemyClass && !SpawnPoints.IsEmpty())
	{
		const int32 IndiceAleatorio = FMath::RandRange(0, SpawnPoints.Num() - 1);
		USceneComponent* SpawnPointElegido = SpawnPoints[IndiceAleatorio];

		if (SpawnPointElegido)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			GetWorld()->SpawnActor<AActor>(EnemyClass, SpawnPointElegido->GetComponentTransform(), SpawnParams);
		}

		GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawner::SpawnEnemy, SpawnDelay, false);

		EnemySpawnCount++;

		if (EnemySpawnCount == 7) {
			SpawnDelay = SpawnDelay - 1;
			EnemySpawnCount = 0;
		}

	}
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

