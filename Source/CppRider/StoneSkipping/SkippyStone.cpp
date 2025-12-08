// Fill out your copyright notice in the Description page of Project Settings.


#include "StoneSkipping/SkippyStone.h"

// Sets default values
ASkippyStone::ASkippyStone()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

// Called to bind functionality to input
void ASkippyStone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

