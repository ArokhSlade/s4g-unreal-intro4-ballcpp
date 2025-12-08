// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SkippyStone.generated.h"

class USpringArmComponent;
class UCameraComponent;

USTRUCT(BlueprintType)
struct FSkippyStoneInput
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skippy Stone|Input")
	float LeanSideways;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skippy Stone|Input")
	uint32 bBoost : 1;
};


UCLASS()
class CPPRIDER_API ASkippyStone : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASkippyStone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnBoostPressedInput();
	void OnBoostReleasedInput();
	void OnLeanSidewaysInput(float AxisValue);

	UFUNCTION(BlueprintNativeEvent, Category = SkippyStone)
	void Boost(FVector Impulse);

	UFUNCTION(BlueprintNativeEvent, Category = SkippyStone)
	void LeanSideways(FVector Force);


protected:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skippy Stone")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skippy Stone")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skippy Stone")
	UCameraComponent* Camera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skippy Stone|Input")
	FSkippyStoneInput SkippyStoneInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skippy Stone")
	float LeanSidewaysStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skippy Stone")
	float BoostStrength;
	
};
