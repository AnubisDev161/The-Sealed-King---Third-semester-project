// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvQueryTest_OnScreen.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "AIModule.h"


UEnvQueryTest_OnScreen::UEnvQueryTest_OnScreen()
{
	Cost = EEnvTestCost::Low;
	ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();
	TestPurpose = EEnvTestPurpose::Score;
	ScoringEquation = EEnvTestScoreEquation::Linear;
	FilterType = EEnvTestFilterType::Maximum;
}

//
//Scores according to the dot product of the deprojected screen center direction and the
//direction from the deprojected screen center location to the item's location
void UEnvQueryTest_OnScreen::RunTest(FEnvQueryInstance& queryInstance) const
{
	UE_LOG(LogTemp, Display, TEXT("Running on screen EQS test!"));

	FVector2D viewportSize;

	queryInstance.World->GetGameViewport()->GetViewportSize(viewportSize);
	const float viewportCenterX = viewportSize.X / 2;
	const float viewportSizeY = viewportSize.Y / 2;

	UObject* owner = queryInstance.Owner.Get();

	FloatValueMin.BindData(owner, queryInstance.QueryID);
	const float minThreasholdValue = FloatValueMin.GetValue();

	FloatValueMax.BindData(owner, queryInstance.QueryID);
	const float maxThreasholdValue = FloatValueMax.GetValue();

	FVector screenCenterWorldDirection;
	FVector screenCenterWorldLocation;

	queryInstance.World->GetFirstPlayerController()->DeprojectScreenPositionToWorld(viewportCenterX, viewportSizeY, screenCenterWorldLocation, screenCenterWorldDirection);

	for (FEnvQueryInstance::ItemIterator iterator(this, queryInstance); iterator; ++iterator) 
	{
		auto itemLocation = GetItemLocation(queryInstance, iterator);

		// get direction from screen center to item location
		FVector directionFromCenterToItem = (itemLocation - screenCenterWorldLocation).GetSafeNormal();

		auto dotProduct = directionFromCenterToItem.Dot(screenCenterWorldDirection);

		iterator.SetScore(TestPurpose, FilterType, dotProduct, minThreasholdValue, maxThreasholdValue);
	}
}
