// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ExecCalc_Damage.generated.h"

/**
 * 
 */
class UAbilitySystemComponent;
class AActor;
class ICombatInterface;
struct FGameplayEffectSpec;
struct FGameplayTagContainer;
struct FAggregatorEvaluateParameters;

UCLASS()
class AURA_API UExecCalc_Damage : public UGameplayEffectExecutionCalculation
{
    GENERATED_BODY()

public:
    UExecCalc_Damage();

    virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
                                        FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;


};