// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * 
 */
class AURA_API ICombatInterface
{
    GENERATED_BODY()

public:
    virtual int32 GetPlayerLevel();
    virtual FVector GetCombatSocketLocation();

    UFUNCTION(BlueprintImplementableEvent, blueprintCallable)
    void UpdateFacingTarget(const FVector& Target);
};