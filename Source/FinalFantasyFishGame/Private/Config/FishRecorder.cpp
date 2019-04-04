// Fill out your copyright notice in the Description page of Project Settings.

#include "FishRecorder.h"

#include "XmlParser/Public/XmlFile.h"

void UFishRecorder::LoadRecorder(FXmlNode* xmlNode)
{
	URecorderBase::LoadRecorder(xmlNode);

	FString itemIdString = xmlNode->GetAttribute(TEXT("itemId"));
	FString radarIconString = xmlNode->GetAttribute(TEXT("radarIcon"));
	FString difficultyString = xmlNode->GetAttribute(TEXT("difficulty"));

	itemId = FCString::Atoi(*itemIdString);
	radarIcon = FCString::Atoi(*radarIconString);
	difficulty = FCString::Atof(*difficultyString);

	for (FXmlNode* childrenNode : xmlNode->GetChildrenNodes())
	{
		//加载鱼饵map
		if (childrenNode->GetTag() == TEXT("BaitMap"))
		{
			for (FXmlNode* baitNode : childrenNode->GetChildrenNodes())
			{
				int id = 0;
				float attactChance = 0;
				FString idString = baitNode->GetAttribute(TEXT("id"));
				if (!idString.IsEmpty())
				{
					id = FCString::Atoi(*idString);
				}
				FString attactChanceString = baitNode->GetAttribute(TEXT("attactChance"));
				if (!attactChanceString.IsEmpty())
				{
					attactChance = FCString::Atof(*attactChanceString);
				}
				baitMap.Add(id, attactChance);
			}
		}
	}
}

FString UFishRecorder::GetRecordName()
{
	return TEXT("Fish");
}

int UFishRecorder::GetItemId()
{
	return itemId;
}

int UFishRecorder::GetRadarIcon()
{
	return radarIcon;
}

float UFishRecorder::GetDifficulty()
{
	return difficulty;
}

TMap<int, float> UFishRecorder::GetBaitMap()
{
	return baitMap;
}
