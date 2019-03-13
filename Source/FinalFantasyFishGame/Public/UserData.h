// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserData.generated.h"

class UGameManager;
/**
 * 
 */
UCLASS()
class FINALFANTASYFISHGAME_API UUserData : public UObject
{
	GENERATED_BODY()
	
public:
	UUserData();

	void Save();

	int GetHour();

	int GetMinute();

	int GetSecond();

	bool GetIsFixedTime();
protected:
	void Load();

	UGameManager* gameManager = nullptr;

	//保存路径
	FString savePath;

	int hour = 6;//时
	int minute = 0;//分
	int second = 0;//秒

	bool isFixedTime = false;//是否固定时间
};
