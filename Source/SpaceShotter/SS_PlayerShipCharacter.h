// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SS_PlayerShipCharacter.generated.h"

class UInputAction;
class UInputActionValue;
class ASS_PlayerProjectile;

UCLASS()
class SPACESHOTTER_API ASS_PlayerShipCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	ASS_PlayerShipCharacter();


	//COMPONENTS
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* ShipMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USceneComponent* FirePoint;


	//Variables

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	float playerLife = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	float bulletDamage = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	bool bCanFire = true;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "ActorLogic")
	float FireDelay = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	float MinFireDelay = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	float FireDelaySubtract = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	float DeathDelay = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	float MovementSpeed = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	TSubclassOf<ASS_PlayerProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	FName BulletTag = "Bullet";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	FName PowerUpTag = "PowerUp";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	FName LevelToOpen = "Menu";
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//InputAction
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ShootAction;

	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void Move(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable, Category = "Shoot")
	void Shoot();

	UFUNCTION()
	void SetCanFireTrue();
	
	UFUNCTION()
	void SetDeath();

	FTimerHandle FireTimerHandle;
	FTimerHandle DeathTimerHandle;

	UFUNCTION()
	void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
