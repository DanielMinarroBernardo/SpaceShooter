// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SS_PlayerShipCharacter.generated.h"

class UInputAction;
class UInputActionValue;

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
	bool bCanFire = true;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "ActorLogic")
	float FireDelay = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	float MovementSpeed = 1.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//InputAction
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void Move(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
