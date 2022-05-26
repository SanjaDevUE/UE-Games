// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CubeCivilization : ModuleRules
{
	public CubeCivilization(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;
	
		PublicDependencyModuleNames.AddRange(new string[] 
			{ "Core", "CoreUObject", "Engine", "InputCore", "AIModule", "UMG", "Slate", "SlateCore", "RHI", "RenderCore", "Landscape", "GameplayTags", "NavigationSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		
		// Setup Gameplay Debugger.
		if (Target.bBuildDeveloperTools || (Target.Configuration != UnrealTargetConfiguration.Shipping && Target.Configuration != UnrealTargetConfiguration.Test))
		{
			PrivateDependencyModuleNames.Add("GameplayDebugger");
			PublicDefinitions.Add("WITH_GAMEPLAY_DEBUGGER=1");
		}

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
