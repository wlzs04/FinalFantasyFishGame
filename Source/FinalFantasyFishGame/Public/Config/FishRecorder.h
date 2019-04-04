// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Config/RecorderBase.h"
#include "FishRecorder.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FINALFANTASYFISHGAME_API UFishRecorder : public URecorderBase
{
	GENERATED_BODY()
public:
	void LoadRecorder(FXmlNode* xmlNode) override;

	FString GetRecordName() override;

	//获得物品Id
	UFUNCTION(BlueprintCallable)
	int GetItemId();

	//获得雷达显示图标
	UFUNCTION(BlueprintCallable)
	int GetRadarIcon();

	//获得获得难度
	UFUNCTION(BlueprintCallable)
	float GetDifficulty();

	//获得鱼饵map
	UFUNCTION(BlueprintCallable)
	TMap<int, float> GetBaitMap();
private:
	int itemId;
	int radarIcon;
	float difficulty;

	TMap<int, float> baitMap;
};
