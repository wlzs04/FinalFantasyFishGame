// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/Config/RecorderBase.h"

#include "XmlParser/Public/XmlFile.h"

void URecorderBase::LoadRecorder(FXmlNode* xmlNode)
{
	FString idString = xmlNode->GetAttribute(TEXT("id"));
	if (!idString.IsEmpty())
	{
		id = FCString::Atoi(*idString);
		valueMap.Add("id", idString);
	}
}

int URecorderBase::GetId()
{
	return id;
}

FString URecorderBase::GetValueByName(FString name)
{
	if (valueMap.Contains(name))
	{
		return valueMap[name];
	}
	return FString();
}
