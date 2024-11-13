// Fill out your copyright notice in the Description page of Project Settings.


#include "ABulletShell.h"

// Sets default values
AABulletShell::AABulletShell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ShellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShellMesh"));
	RootComponent = ShellMesh;

	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	/*ProjectileComponent->InitialSpeed = 200;
	ProjectileComponent->MaxSpeed = 800;
	ProjectileComponent->Velocity = FVector(0, -1, 0) * ProjectileComponent->InitialSpeed;*/
}

// Called when the game starts or when spawned
void AABulletShell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABulletShell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABulletShell::SetEjectionVelocity(FVector EjectionDirection, float EjectionSpeed)
{
	//ProjectileComponent->InitialSpeed = 800;
	//ProjectileComponent->MaxSpeed = 4000;
	ProjectileComponent->Velocity = EjectionDirection * EjectionSpeed;

}

