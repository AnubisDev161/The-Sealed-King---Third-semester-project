// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_RunEQSQueryTeleport.h"

void UBTT_RunEQSQueryTeleport::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult)
{
	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);
	
	
}

EBTNodeResult::Type UBTT_RunEQSQueryTeleport::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	return EBTNodeResult::Type(Super::ExecuteTask(OwnerComp, NodeMemory));
}
