// Fill out your copyright notice in the Description page of Project Settings.

#include "TimeData.h"

UTimeData::UTimeData()
{
	gameDuringSecond = 0;
}

UTimeData::~UTimeData()
{

}

void UTimeData::Tick(float secondTime)
{
	gameDuringSecond += secondTime;
}

float UTimeData::GetHours()
{
	return (int)GetAllHours()% 24;
}

float UTimeData::GetAllHours()
{
	return gameDuringSecond/3600;
}

float UTimeData::GetMinutes()
{
	return (int)GetAllMinutes()%60;
}

float UTimeData::GetAllMinutes()
{
	return gameDuringSecond / 60;
}

float UTimeData::GetSeconds()
{
	return ((int)gameDuringSecond)/60;
}

float UTimeData::GetAllSeconds()
{
	return gameDuringSecond;
}

float UTimeData::GetMilliseconds()
{
	return (gameDuringSecond-(int)gameDuringSecond)*1000;
}

float UTimeData::GetAllMilliseconds()
{
	return gameDuringSecond*1000;
}
