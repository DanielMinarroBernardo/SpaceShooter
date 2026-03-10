// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_PlayerShipCharacter.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"

// Sets default values
ASS_PlayerShipCharacter::ASS_PlayerShipCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>((TEXT("ShipMesh")));
	ShipMesh->SetupAttachment(GetMesh());
	
	FirePoint = CreateDefaultSubobject<USceneComponent>((TEXT("FirePoint")));
	FirePoint->SetupAttachment(RootComponent);

	GetCapsuleComponent()->SetCapsuleHalfHeight(94.0f);
	GetCapsuleComponent()->SetCapsuleRadius(94.0f);
}

// Called when the game starts or when spawned
void ASS_PlayerShipCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASS_PlayerShipCharacter::Move(const FInputActionValue& Value)
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, "MovingCharacter");

	FVector2D MovementVector = Value.Get<FVector2D>();
	if (GetController()) {
		AddMovementInput(GetActorRightVector() * MovementSpeed, MovementVector.X, false);
		AddMovementInput(GetActorForwardVector() * MovementSpeed, MovementVector.Y, false);
	}

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

	if (APlayerController* PC = Cast<APlayerController>(GetController())) {

		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
			
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASS_PlayerShipCharacter::Move);

		}
		
	}

}

