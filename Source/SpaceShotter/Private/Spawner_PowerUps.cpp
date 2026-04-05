// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner_PowerUps.h"

// Sets default values
ASpawner_PowerUps::ASpawner_PowerUps()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner_PowerUps::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner_PowerUps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

