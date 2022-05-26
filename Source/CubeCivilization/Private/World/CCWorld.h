// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Chunk/ChunkBase.h"
#include "GameFramework/Actor.h"
#include "Utils/CCEnums.h"
#include "CCWorld.generated.h"

UCLASS()
class ACCWorld : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditInstanceOnly, Category= "World")
	TSubclassOf<AChunkBase> ChunkType;

	UPROPERTY(EditInstanceOnly, Category= "World")
	int DrawDistance = 5;

	UPROPERTY(EditInstanceOnly, Category= "World")
	TObjectPtr<UMaterialInterface> Material;

	UPROPERTY(EditInstanceOnly, Category= "World")
	int Size = 32;

	UPROPERTY(EditInstanceOnly, Category= "World")
	EGenerationType GenerationType;

	UPROPERTY(EditInstanceOnly, Category= "World")
	float Frequency = 0.03f;

	// Set default values for this actors properties
	ACCWorld();

protected:
	// called when the game start or when spawned
	virtual void BeginPlay() override;

private:
	int ChunkCount;

	void Generate3DWorld();
	void Generate2DWorld();

};