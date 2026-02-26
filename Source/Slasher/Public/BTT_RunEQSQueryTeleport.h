// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/EnvQueryManager.h"

#include "BehaviorTree/Tasks/BTTask_RunEQSQuery.h"
#include "BTT_RunEQSQueryTeleport.generated.h"

/**
 * 
 */
UCLASS()
class SLASHER_API UBTT_RunEQSQueryTeleport : public UBTTask_RunEQSQuery
{
	GENERATED_BODY()
	
protected:
	virtual void OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult) override;
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult) override;



	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector> PossibleTeleportLocations;

};

