// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/Config/RecorderBase.h"

#include "XmlParser/Public/XmlFile.h"

void URecorderBase::LoadRecorder(FXmlNode* xmlNode)
{
	for (int i = 0; i < xmlNode->GetAttributes().Num(); i++)
	{
		FXmlAttribute attribute = xmlNode->GetAttributes()[i];
		valueMap.Add(attribute.GetTag(), attribute.GetValue());
	}

	FString idString = xmlNode->GetAttribute(TEXT("id"));
	if (!idString.IsEmpty())
	{
		id = FCString::Atoi(*idString);
		valueMap.Add("id", idString);
	}
}

FString URecorderBase::GetRecordName()
{
	return FString(TEXT("Record"));
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
