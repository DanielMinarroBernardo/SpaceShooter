// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_PlayerShipCharacter.h"

// Sets default values
ASS_PlayerShipCharacter::ASS_PlayerShipCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>((TEXT("ShipMesh")));
	ShipMesh->SetupAttachment(GetMesh());
	
	FirePoint = CreateDefaultSubobject<USceneComponent>((TEXT("FirePoint")));
	FirePoint->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASS_PlayerShipCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASS_PlayerShipCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ASS_PlayerShipCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

