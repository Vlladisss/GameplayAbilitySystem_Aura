// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "DamageTextComponent.generated.h"

UENUM(BlueprintType)
enum class EAuraDamageType : uint8
{
    NormalAttack,
    BlockedAttack,
    CriticalAttack,
    BlockedAndCritical
};

/**
 * 
 */
UCLASS()
class AURA_API UDamageTextComponent : public UWidgetComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void SetDamageText(float Damage,EAuraDamageType AuraDamageType);

    UFUNCTION(BlueprintCallable)
    void SetDamageType(float Damage, bool bBlockedHit, bool bCriticalHit);
};