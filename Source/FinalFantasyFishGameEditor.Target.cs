// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class FinalFantasyFishGameEditorTarget : TargetRules
{
	public FinalFantasyFishGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("FinalFantasyFishGame");
	}
}
