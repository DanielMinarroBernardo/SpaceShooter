// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_PlayerShipCharacter.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "SS_PlayerProjectile.h"
#include "InputAction.h"
#include "Kismet/GameplayStatics.h"
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
	OnActorBeginOverlap.AddUniqueDynamic(this, &ASS_PlayerShipCharacter::BeginOverlap);
}

void ASS_PlayerShipCharacter::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	if (OtherActor->ActorHasTag(BulletTag)) {
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, "PlayerGotHitByABullet");
		OtherActor->Destroy();
		playerLife = playerLife - 1;
		if (playerLife == 0) {
			GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ASS_PlayerShipCharacter::SetDeath, DeathDelay, false);
		}
	}
	if (OtherActor->ActorHasTag(PowerUpTag)) {
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, "PlayerTouchPowerUp");
		OtherActor->Destroy();

		if (FireDelay > MinFireDelay) {
			FireDelay = FireDelay - FireDelaySubtract;
			GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, "FireDelayChange");
		}
	}
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

void ASS_PlayerShipCharacter::Shoot()
{
	if (bCanFire) {
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, "Shooting");	
		
		//Spawn
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		GetWorld()->SpawnActor<AActor>(ProjectileClass, FirePoint->GetComponentTransform(), SpawnParams);

		bCanFire = false;
		//INIT TIMER
		GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ASS_PlayerShipCharacter::SetCanFireTrue, FireDelay, false);
	}
}

void ASS_PlayerShipCharacter::SetCanFireTrue()
{
	bCanFire = true;
}

void ASS_PlayerShipCharacter::SetDeath()
{
	UGameplayStatics::OpenLevel(this, LevelToOpen);
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
			EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &ASS_PlayerShipCharacter::Shoot);

		}
		
	}

}

