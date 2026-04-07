// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUp.h"

// Sets default values
APowerUp::APowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>((TEXT("Capsule")));
	Capsule->SetupAttachment(RootComponent);

	PowerUpMesh = CreateDefaultSubobject<UStaticMeshComponent>((TEXT("Mesh")));
	PowerUpMesh->SetupAttachment(Capsule);
}



// Called when the game starts or when spawned
void APowerUp::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, "PowerUpSpawned");

}

void APowerUp::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag(PlayerTag)) {
		
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, "Overlaped with player");

		if (ActualName == FireDelayName) {
			ChangeFireDelay();
		}

	}
}

// Called every frame
void APowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

