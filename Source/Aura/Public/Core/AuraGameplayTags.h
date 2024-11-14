// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *
 * Singleton containing native Gameplay Tags
 */
struct FAuraGameplayTags
{
public:
    static const FAuraGameplayTags& Get();
    static void InitializeNativeGameplayTags();

    //************************** P R I M A R Y - A T T R I B U T E S ******************************
    FGameplayTag Attributes_Primary_Strength;
    FGameplayTag Attributes_Primary_Intelligence;
    FGameplayTag Attributes_Primary_Resilience;
    FGameplayTag Attributes_Primary_Vigor;

    
    //************************ S E C O N D A R Y - A T T R I B U T E S ****************************
    FGameplayTag Attributes_Secondary_Armor;
    FGameplayTag Attributes_Secondary_ArmorPenetration;
    FGameplayTag Attributes_Secondary_BlockChance;
    FGameplayTag Attributes_Secondary_CriticalHitChance;
    FGameplayTag Attributes_Secondary_CriticalHitDamage;
    FGameplayTag Attributes_Secondary_CriticalHitResistance;
    FGameplayTag Attributes_Secondary_HealthRegeneration;
    FGameplayTag Attributes_Secondary_ManaRegeneration;
    FGameplayTag Attributes_Secondary_MaxHealth;
    FGameplayTag Attributes_Secondary_MaxMana;

    
    //****************************** I N P U T - K E Y B O A R D **********************************
    FGameplayTag InputTag_LMB;
    FGameplayTag InputTag_RMB;
    FGameplayTag InputTag_1;
    FGameplayTag InputTag_2;
    FGameplayTag InputTag_3;
    FGameplayTag InputTag_4;

    //*************************************** D A M A G E *******************************************
    FGameplayTag Damage;
    FGameplayTag Effects_HitReact;
    
private:
    static FAuraGameplayTags GameplayTags;
};
