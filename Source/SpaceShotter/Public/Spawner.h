// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUp.h"
#include "Spawner.generated.h"

UCLASS()
class SPACESHOTTER_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SpawnPoint0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SpawnPoint1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SpawnPoint2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SpawnPoint3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SpawnPoint4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SpawnPoint5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	TSubclassOf<APowerUp> PowerUpClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	TSubclassOf<AActor> EnemyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	FString WhatDoISpawn = "PowerUp";


	UPROPERTY(BlueprintReadOnly, Category = "ActorLogic")
	TArray<USceneComponent*> SpawnPoints;

	FTimerHandle SpawnTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	float SpawnDelay = 20.0f;

	int32 indexbefore = 0;

	int EnemySpawnCount = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void SpawnPowerUp();

	UFUNCTION()
	void SpawnEnemy();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};