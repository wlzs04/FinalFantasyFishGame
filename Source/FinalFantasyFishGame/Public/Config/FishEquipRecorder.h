// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Config/RecorderBase.h"
#include "FishEquipRecorder.generated.h"

//钓具类型
UENUM(BlueprintType)
enum class FishEquipType :uint8
{
	Rod UMETA(DisplayName = "钓竿"),
	Bait UMETA(DisplayName = "钓饵"),
};

/**
 * 
 */
UCLASS(BlueprintType)
class FINALFANTASYFISHGAME_API UFishEquipRecorder : public URecorderBase
{
	GENERATED_BODY()
public:
	void LoadRecorder(FXmlNode* xmlNode) override;

	FString GetRecordName() override;

	//获得类型
	UFUNCTION(BlueprintCallable)
	FishEquipType GetFishEquipType();

	//获得物品Id
	UFUNCTION(BlueprintCallable)
	int GetItemId();

private:
	FishEquipType fishEquipType;
	int itemId;
};
