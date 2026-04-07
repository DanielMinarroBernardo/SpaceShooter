// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "PowerUp.generated.h"

UCLASS()
class SPACESHOTTER_API APowerUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUp();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PowerUpMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* Capsule;	


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	FName PlayerTag = "Player";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	FName FireDelayName = "FireDelay";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorLogic")
	FName ActualName;

	UFUNCTION(BlueprintImplementableEvent, Category = "ActorLogic")
	void ChangeFireDelay();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UFUNCTION()
	void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
