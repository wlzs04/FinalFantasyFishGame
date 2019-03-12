// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"
#include "Kismet/KismetSystemLibrary.h"

void UGameManager::InitGameTime()
{
	realTimeData = NewObject<UTimeData>(this);
	gameTimeData = NewObject<UTimeData>(this);
	StartTime();
}

void UGameManager::StartTime()
{
	startTime = true;
}

void UGameManager::StopTime()
{
	startTime = false;
}

bool UGameManager::IsStartTime()
{
	return startTime;
}

void UGameManager::Tick(float secondTime)
{
	if (startTime)
	{
		realTimeData->Tick(secondTime);
		gameTimeData->Tick(secondTime*gameAndRealTimeRate);
	}
}

UTimeData* UGameManager::GetRealDuringTime()
{
	return realTimeData;
}

UTimeData* UGameManager::GetGameDuringTime()
{
	return gameTimeData;
}

void UGameManager::SetGameAndRealTimeRate(float gameAndRealTimeRate)
{
	this->gameAndRealTimeRate = gameAndRealTimeRate;
}

float UGameManager::GetGameAndRealTimeRate()
{
	return gameAndRealTimeRate;
}

void UGameManager::LoadUserData()
{
	userData = NewObject<UUserData>(this);
	gameTimeData->SetTime(userData->GetHour(), userData->GetMinute(), userData->GetSecond());
}

void UGameManager::SaveUserData()
{
	userData->Save();
}

void UGameManager::ExitGame()
{
	SaveUserData();
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit,true);
}
