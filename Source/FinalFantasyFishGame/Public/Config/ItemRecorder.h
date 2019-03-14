// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RecorderBase.h"
#include "ItemRecorder.generated.h"

/**
 * 
 */
UCLASS()
class FINALFANTASYFISHGAME_API UItemRecorder : public URecorderBase
{
	GENERATED_BODY()
public:
	void LoadRecorder(FXmlNode* xmlNode) override;

	FString GetName();
	FString GetDescript();
private:
	FString name;
	FString descript;
};
