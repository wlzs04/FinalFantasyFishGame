// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Config/RecorderBase.h"
#include "ConfigManager.generated.h"

/**
 * 
 */
UCLASS()
class FINALFANTASYFISHGAME_API UConfigManager : public UObject
{
	GENERATED_BODY()
public:
	//获得指定名称的配置
	UFUNCTION(BlueprintCallable)
	TMap<int, URecorderBase*> GetConfigByName(UClass* recorderClass, FString configName);

	//加载指定名称的配置
	UFUNCTION(BlueprintCallable)
	void LoadConfigByName(UClass* recorderClass, FString configName);

private:
	TMap<FString, TMap<int,URecorderBase*>*> configMap;

	FString configRootPath = TEXT("GameContent/Data/Config/");
};
