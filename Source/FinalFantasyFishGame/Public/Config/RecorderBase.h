// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RecorderBase.generated.h"

class FXmlNode;

/**
 * 
 */
UCLASS()
class FINALFANTASYFISHGAME_API URecorderBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void LoadRecorder(FXmlNode* xmlNode);

	virtual FString GetRecordName();

	//获得Id
	UFUNCTION(BlueprintCallable)
	int GetId();

	//获得指定名称的值
	UFUNCTION(BlueprintCallable)
	FString GetValueByName(FString name);
protected:

	int id;
	TMap<FString, FString> valueMap;
};
