// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "SS_PlayerProjectile.generated.h"

UCLASS()
class SPACESHOTTER_API ASS_PlayerProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ASS_PlayerProjectile();
	// Sets default values for this actor's properties

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
	float LifeSpan = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
	float BulletSpeed = 600;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
	FName WallTag = "Wall";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
	FName EnemyTag = "Enemy";

	UFUNCTION()
	void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
