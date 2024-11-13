// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ABulletShell.generated.h"


UCLASS()
class FIRSTPERSONSHOOTER_API AABulletShell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABulletShell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = "ShellMesh")
	UStaticMeshComponent* ShellMesh;

	UPROPERTY(EditAnywhere, Category = "ProjectileComponent")
	UProjectileMovementComponent* ProjectileComponent;

	UFUNCTION(BlueprintCallable, Category = "Ejection")
	void SetEjectionVelocity(FVector EjectionDirection, float EjectionSpeed);

	//void EjectShell(FVector EjectionDirection, float EjectionSpeed);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
