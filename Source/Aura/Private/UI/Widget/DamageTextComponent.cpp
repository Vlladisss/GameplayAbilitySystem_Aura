// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"


#include "UI/Widget/DamageTextComponent.h"

void UDamageTextComponent::SetDamageType(float Damage, bool bBlockedHit, bool bCriticalHit)
{
    if (bBlockedHit && !bCriticalHit)
    {
        SetDamageText(Damage, EAuraDamageType::BlockedAttack);
    }
    else if (bCriticalHit && !bBlockedHit)
    {
        SetDamageText(Damage, EAuraDamageType::CriticalAttack);
    }
    else if (bCriticalHit && bBlockedHit)
    {
        SetDamageText(Damage, EAuraDamageType::BlockedAndCritical);
    }
    else if (!bCriticalHit && !bBlockedHit)
    {
        SetDamageText(Damage, EAuraDamageType::NormalAttack);
    }

}