// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TimeData.h"
#include "UserData.h"
#include "ConfigManager.h"
#include "GameManager.generated.h"

/**
 * 游戏管理类
 */
UCLASS(BlueprintType)
class FINALFANTASYFISHGAME_API UGameManager : public UGameInstance
{
	GENERATED_BODY()

public:

	//初始化管理类
	UFUNCTION(BlueprintCallable)
	void InitManager();

	//初始化游戏时间
	UFUNCTION(BlueprintCallable)
	void InitGameTime();

	//开始计时
	UFUNCTION(BlueprintCallable)
	void StartTime();

	//停止计时
	UFUNCTION(BlueprintCallable)
	void StopTime();

	//是否计时
	UFUNCTION(BlueprintCallable)
	bool IsStartTime();

	//每帧执行一次
	UFUNCTION(BlueprintCallable)
	void Tick(float secondTime);

	//获得游戏运行的时间
	UFUNCTION(BlueprintCallable)
	UTimeData* GetRealDuringTime();

	//获得游戏运行的时间
	UFUNCTION(BlueprintCallable)
	UTimeData* GetGameDuringTime();

	//设置游戏和现实时间的比率
	UFUNCTION(BlueprintCallable)
	void SetGameAndRealTimeRate(float gameAndRealTimeRate);

	//设置游戏和现实时间的比率
	UFUNCTION(BlueprintCallable)
	float GetGameAndRealTimeRate();

	//加载用户数据
	UFUNCTION(BlueprintCallable)
	void LoadUserData();

	//保存用户数据
	UFUNCTION(BlueprintCallable)
	void SaveUserData();

	//设置是否固定时间
	UFUNCTION(BlueprintCallable)
	void SetIsFixedTime(bool isFixedTime);

	//获得是否固定时间
	UFUNCTION(BlueprintCallable)
	bool GetIsFixedTime();

	//结束游戏
	UFUNCTION(BlueprintCallable)
	void ExitGame();

	//获得配置管理器
	UFUNCTION(BlueprintCallable)
	UConfigManager* GetConfigManager();

private:
	UPROPERTY()
	UTimeData* realTimeData = nullptr;

	UPROPERTY()
	UTimeData* gameTimeData = nullptr;

	UPROPERTY()
	UUserData* userData = nullptr;

	UPROPERTY()
	UConfigManager* configManager = nullptr;

	bool startTime = false;
	float gameAndRealTimeRate = 1;
	bool isFixedTime = false;//是否固定时间
};
