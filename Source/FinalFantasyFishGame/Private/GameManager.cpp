// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Config/ItemRecorder.h"

#include "FileManagerGeneric.h" 
#include "Runtime/ImageWrapper/Public/IImageWrapper.h" 
#include "Runtime/ImageWrapper/Public/IImageWrapperModule.h"
#include "ModuleManager.h"
#include "FileHelper.h"
#include "Engine/Texture2D.h"
#include "LogMacros.h"

void UGameManager::InitAll()
{
	InitGameTime();
	InitManager();
}

void UGameManager::InitManager()
{
	configManager = NewObject<UConfigManager>(this);
}

void UGameManager::InitGameTime()
{
	realTimeData = NewObject<UTimeData>(this);
	gameTimeData = NewObject<UTimeData>(this);
	StartTime();
}

void UGameManager::StartTime()
{
	startTime = true;
}

void UGameManager::StopTime()
{
	startTime = false;
}

bool UGameManager::IsStartTime()
{
	return startTime;
}

void UGameManager::Tick(float secondTime)
{
	if (startTime)
	{
		realTimeData->Tick(secondTime);
		gameTimeData->Tick(secondTime*gameAndRealTimeRate);
	}
}

UTimeData* UGameManager::GetRealDuringTime()
{
	return realTimeData;
}

UTimeData* UGameManager::GetGameDuringTime()
{
	return gameTimeData;
}

void UGameManager::SetGameAndRealTimeRate(float gameAndRealTimeRate)
{
	this->gameAndRealTimeRate = gameAndRealTimeRate;
}

float UGameManager::GetGameAndRealTimeRate()
{
	return gameAndRealTimeRate;
}

void UGameManager::LoadUserData()
{
	userData = NewObject<UUserData>(this);
	gameTimeData->SetTime(userData->GetHour(), userData->GetMinute(), userData->GetSecond());
	SetIsFixedTime(userData->GetIsFixedTime());
	SetGameAndRealTimeRate(userData->GetGameAndRealTimeRate());
}

void UGameManager::SaveUserData()
{
	userData->Save();
}

UUserData* UGameManager::GetUserData()
{
	return userData;
}

void UGameManager::SetIsFixedTime(bool isFixedTime)
{
	this->isFixedTime = isFixedTime;
	if (isFixedTime)
	{
		StopTime();
	}
	else
	{
		StartTime();
	}
}

bool UGameManager::GetIsFixedTime()
{
	return isFixedTime;
}

void UGameManager::ExitGame()
{
	SaveUserData();
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit,true);
}

UConfigManager * UGameManager::GetConfigManager()
{
	return configManager;
}

UTexture2D* UGameManager::LoadTexture2D(FString path, bool& IsValid, int32& OutWidth, int32& OutHeight)
{
	path = FPaths::ProjectContentDir() + TEXT("GameContent/Data/Texture/") + path;
	UTexture2D* Texture = nullptr;
	IsValid = false;
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*path))
	{
		return nullptr;
	}
	TArray<uint8> RawFileData;
	if (!FFileHelper::LoadFileToArray(RawFileData, *path))
	{
		return nullptr;
	}
	TSharedPtr<IImageWrapper> ImageWrapper ;
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	if (path.EndsWith(".png"))
	{
		ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
	}
	else if (path.EndsWith(".jpg") || path.EndsWith(".jpeg"))
	{
		ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);
	}
	else if (path.EndsWith(".bmp"))
	{
		ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::BMP);
	}
	else if (path.EndsWith(".ico"))
	{
		ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::ICO);

	}
	else if (path.EndsWith("exr"))
	{
		ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::EXR);
	}
	else if (path.EndsWith(".icns"))
	{
		ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::ICNS);
	}
	else
	{
		UE_LOG(LogLoad, Error, TEXT("未知图片文件加载失败：%s"), *path);
	}
	if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
	{
		const TArray<uint8>* UncompressedRGBA = nullptr;
		if (ImageWrapper->GetRaw(ERGBFormat::RGBA, 8, UncompressedRGBA))
		{
			Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_R8G8B8A8);
			if (Texture != nullptr)
			{
				IsValid = true;
				OutWidth = ImageWrapper->GetWidth();
				OutHeight = ImageWrapper->GetHeight();
				void* TextureData = Texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData, UncompressedRGBA->GetData(), UncompressedRGBA->Num());
				Texture->PlatformData->Mips[0].BulkData.Unlock();
				Texture->UpdateResource();
			}
		}
	}
	return Texture;
}
