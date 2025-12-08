// Fill out your copyright notice in the Description page of Project Settings.


#include "SkippyStone.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASkippyStone::ASkippyStone()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	LeanSidewaysStrength = 100'000.0f;
	Mesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ASkippyStone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkippyStone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SkippyStoneInput.bBoost)
	{
		FVector Impulse { 0.f, 0.f, BoostStrength };
		Boost(Impulse);
	}

	FVector LeanSidewaysForce = FVector{ 0.f, SkippyStoneInput.LeanSideways * LeanSidewaysStrength, 0.f };
	LeanSideways(LeanSidewaysForce);

}

// Called to bind functionality to input
void ASkippyStone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveRight", this, &ASkippyStone::OnLeanSidewaysInput);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ASkippyStone::OnBoostPressedInput);
	InputComponent->BindAction("Jump", IE_Released, this, &ASkippyStone::OnBoostReleasedInput);
}

void ASkippyStone::OnBoostPressedInput()
{
	SkippyStoneInput.bBoost = true;
}

void ASkippyStone::OnBoostReleasedInput()
{
	SkippyStoneInput.bBoost = false;
}

void ASkippyStone::OnLeanSidewaysInput(float AxisValue)
{
	SkippyStoneInput.LeanSideways = AxisValue;
}

void ASkippyStone::Boost_Implementation(FVector Impulse)
{
	Mesh->AddImpulse(Impulse);
}

void ASkippyStone::LeanSideways_Implementation(FVector Force)
{
	Mesh->AddForce(Force);
}