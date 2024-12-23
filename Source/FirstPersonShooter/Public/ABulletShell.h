// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileComponent")
	UProjectileMovementComponent* ProjectileComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Sound")
	bool bHasPlayedSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* SoundEffect1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* SoundEffect2;




	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	virtual void OnConstruction(const FTransform& Transform) override;



	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
