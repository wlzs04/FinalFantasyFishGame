// Fill out your copyright notice in the Description page of Project Settings.

#include "UserData.h"
#include "GameManager.h"

#include "Paths.h"
#include "Runtime/XmlParser/Public/XmlParser.h"
#include "Runtime/XmlParser/Public/FastXml.h" 
#include "XmlParser/Public/XmlFile.h"
#include "LogMacros.h"
#include "Engine/World.h"

UUserData::UUserData() :UObject()
{
	savePath = FPaths::ProjectContentDir() + TEXT("GameContent/Data/UserData.xml");
	Load();
}

void UUserData::Save()
{
	gameManager = Cast<UGameManager>(GetWorld()->GetGameInstance());
	UTimeData* gameDuringTime = gameManager->GetGameDuringTime();
	hour = gameDuringTime->GetHours();
	minute = gameDuringTime->GetMinutes();
	second = gameDuringTime->GetSeconds();
	FString xmlContent = TEXT("<UserData ");
	xmlContent.Append(TEXT("hour=\"") + FString::FromInt(hour) + TEXT("\" "));
	xmlContent.Append(TEXT("minute=\"") + FString::FromInt(minute) + TEXT("\" "));
	xmlContent.Append(TEXT("second=\"") + FString::FromInt(second) + TEXT("\" "));
	xmlContent.Append(TEXT(">\n</UserData>"));

	FXmlFile* xmlFile = new FXmlFile(xmlContent,EConstructMethod::ConstructFromBuffer);
	xmlFile->Save(savePath);
	xmlFile->Clear();
	delete xmlFile;
}

int UUserData::GetHour()
{
	return hour;
}

int UUserData::GetMinute()
{
	return minute;
}

int UUserData::GetSecond()
{
	return second;
}

void UUserData::Load()
{
	FXmlFile* xmlFile = new FXmlFile(savePath);
	if (!xmlFile->IsValid())
	{
		UE_LOG(LogLoad, Error, TEXT("Save文件加载失败：%s"), *savePath);
		return;
	}

	FXmlNode* rootNode = xmlFile->GetRootNode();

	//加载基础属性
	{
		FString hourString = rootNode->GetAttribute(TEXT("hour"));
		hour = FCString::Atoi(*hourString);
		FString minuteString = rootNode->GetAttribute(TEXT("minute"));
		minute = FCString::Atoi(*minuteString);
		FString secondString = rootNode->GetAttribute(TEXT("second"));
		second = FCString::Atoi(*secondString);
	}

	xmlFile->Clear();
	delete xmlFile;
	UE_LOG(LogLoad, Log, TEXT("Save文件：%s加载完成！"), *savePath);
}
