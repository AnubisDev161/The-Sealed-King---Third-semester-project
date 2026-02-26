// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_OnScreen.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "On screen", Description = "The score increases the closer the item is to camera center"))
class SLASHER_API UEnvQueryTest_OnScreen : public UEnvQueryTest
{
	GENERATED_BODY()
public:
	UEnvQueryTest_OnScreen();
protected:
	virtual void RunTest(FEnvQueryInstance& queryInstance) const override;
	 
};
