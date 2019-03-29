// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/Config/FishEquipRecorder.h"

#include "XmlParser/Public/XmlFile.h"

void UFishEquipRecorder::LoadRecorder(FXmlNode* xmlNode)
{
	URecorderBase::LoadRecorder(xmlNode);

	FString fishEquipTypeString = xmlNode->GetAttribute(TEXT("fishEquipType"));
	FString itemIdString = xmlNode->GetAttribute(TEXT("itemId"));

	const UEnum* AnimStateEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("FishEquipType"), true);
	fishEquipType = (FishEquipType)AnimStateEnum->FindEnumIndex(FName(*fishEquipTypeString));

	itemId = FCString::Atoi(*itemIdString);
}

FString UFishEquipRecorder::GetRecordName()
{
	return FString(TEXT("FishEquip"));
}

FishEquipType UFishEquipRecorder::GetFishEquipType()
{
	return fishEquipType;
}

int UFishEquipRecorder::GetItemId()
{
	return itemId;
}
