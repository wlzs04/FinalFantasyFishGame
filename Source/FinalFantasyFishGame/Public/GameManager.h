// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TimeData.h"
#include "GameManager.generated.h"

/**
 * 游戏管理类
 */
UCLASS(BlueprintType)
class FINALFANTASYFISHGAME_API UGameManager : public UGameInstance
{
	GENERATED_BODY()

public:
	//初始化游戏时间
	UFUNCTION(BlueprintCallable)
	void InitGameTime();

	//开始计时
	void StartTime();

	//停止计时
	void StopTime();

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

private:
	UPROPERTY()
	UTimeData* realTimeData = nullptr;

	UPROPERTY()
	UTimeData* gameTimeData = nullptr;

	bool startTime = false;
	float gameAndRealTimeRate = 1;
};
