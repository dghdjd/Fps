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

	bHasPlayedSound = false;

	ProjectileComponent->InitialSpeed = 200;
	ProjectileComponent->MaxSpeed = 1000;

	ProjectileComponent->bAutoActivate = false;
	

}



// Called when the game starts or when spawned
void AABulletShell::BeginPlay()
{
	Super::BeginPlay();

	if (ShellMesh) // Ensure your component is valid
	{
		// Bind the OnHit function to the OnComponentHit event
		ShellMesh->OnComponentHit.AddDynamic(this, &AABulletShell::OnHit);
	}

	
}

// Called every frame
void AABulletShell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABulletShell::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (ProjectileComponent)
	{
		// Generate a random speed multiplier
		float rand = FMath::RandRange(0.5f, 1.5f);


		ProjectileComponent->InitialSpeed *= rand;
		ProjectileComponent->Activate();
	}
}

void AABulletShell::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	bool random = FMath::RandBool();
	if (!bHasPlayedSound) // Only proceed if the sound hasn't played
	{
		// Check if the surface is the ground
		if (Hit.PhysMaterial.IsValid() && Hit.PhysMaterial->SurfaceType == SurfaceType1) // Ground
		{
			// Play sound effect
			if (SoundEffect1 && random)
			{
				UGameplayStatics::PlaySoundAtLocation(this, SoundEffect1, Hit.Location);
				
			}
			else if (SoundEffect2 && !random)
			{
				UGameplayStatics::PlaySoundAtLocation(this, SoundEffect2, Hit.Location);
			}
			bHasPlayedSound = true; // Ensure sound plays only once
		}
	}
}

