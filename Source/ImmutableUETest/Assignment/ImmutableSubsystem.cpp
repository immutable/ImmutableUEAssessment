// Fill out your copyright notice in the Description page of Project Settings.


#include "ImmutableSubsystem.h"

const FString TestEmail = TEXT("Customer@Immutable.com");

FString UImmutableSubsystem::GetEmail() const
{
	return TestEmail;
}

void UImmutableSubsystem::GetEmailAsync(const FImmutableDelegate& Delegate)
{
	if (!StartTimer)
	{
		ImmutableDelegate = Delegate;
		StartTimer = true;
	}
}

void UImmutableSubsystem::Tick(float DeltaTime)
{
	if (StartTimer)
	{
		Timer += DeltaTime;
		if (Timer > 1.f)
		{
			ImmutableDelegate.ExecuteIfBound(TestEmail);
			StartTimer = false;
		}
	}
}

ETickableTickType UImmutableSubsystem::GetTickableTickType() const
{
	return ETickableTickType::Always;
}

TStatId UImmutableSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FImmutableTickable, STATGROUP_Tickables);
}
