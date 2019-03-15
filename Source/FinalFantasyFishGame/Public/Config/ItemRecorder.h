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

	//获得名称
	UFUNCTION(BlueprintCallable)
	FString GetName();

	//获得名称
	UFUNCTION(BlueprintCallable)
	FString GetImagePath();

	//获得描述
	UFUNCTION(BlueprintCallable)
	FString GetDescript();
private:
	FString name;
	FString imagePath;
	FString descript;
};
