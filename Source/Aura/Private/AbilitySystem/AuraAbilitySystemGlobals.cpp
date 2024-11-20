// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"


#include "AbilitySystem/AuraAbilitySystemGlobals.h"
#include "Core/AuraAbilityTypes.h"

FGameplayEffectContext* UAuraAbilitySystemGlobals::AllocGameplayEffectContext() const
{
    return new FAuraGameplayEffectContext();
}