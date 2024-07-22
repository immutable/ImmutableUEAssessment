// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ImmutableSubsystem.generated.h"


DECLARE_DELEGATE_OneParam(FImmutableDelegate, FString);

UCLASS()
class IMMUTABLEUETEST_API UImmutableSubsystem : public UEngineSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:

	FString GetEmail() const;
	void GetEmailAsync(const FImmutableDelegate& Delegate);

	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override;
	virtual TStatId GetStatId() const override;

private:

	FImmutableDelegate ImmutableDelegate;
	float Timer = 0.f;
	bool StartTimer = false;
	
};
