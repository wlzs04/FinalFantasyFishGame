// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/Config/ItemRecorder.h"

#include "XmlParser/Public/XmlFile.h"

void UItemRecorder::LoadRecorder(FXmlNode* xmlNode)
{
	URecorderBase::LoadRecorder(xmlNode);

	name = xmlNode->GetAttribute(TEXT("name"));
	descript = xmlNode->GetAttribute(TEXT("descript"));

	valueMap.Add("name", name);
	valueMap.Add("descript", descript);
}

FString UItemRecorder::GetName()
{
	return name;
}

FString UItemRecorder::GetDescript()
{
	return descript;
}
