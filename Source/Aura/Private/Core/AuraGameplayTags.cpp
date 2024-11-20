// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"


#include "Core/AuraGameplayTags.h"
#include  "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;


const FAuraGameplayTags& FAuraGameplayTags::Get()
{
    return GameplayTags;
}

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
    //************************** P R I M A R Y - A T T R I B U T E S ******************************
    GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"));
    GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"));
    GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience"));
    GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vigor"));

    //************************ S E C O N D A R Y - A T T R I B U T E S ****************************
    GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"));
    GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"));
    GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"));
    GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"));
    GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"));
    GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitResistance"));
    GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegeneration"));
    GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegeneration"));
    GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"));
    GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"));

    //********************************* I N P U T - T A G S **************************************
    GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LMB"));
    GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.RMB"));
    GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.1"));
    GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.2"));
    GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.3"));
    GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.4"));

    //************************************* D A M A G E ******************************************

    // Damage Types
    GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage"));
    GameplayTags.Damage_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Fire"));
    GameplayTags.Damage_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Lightning"));
    GameplayTags.Damage_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Arcane"));
    GameplayTags.Damage_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Damage.Physical"));

    // Resistances
    GameplayTags.Attributes_Resistance_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Resistance.Fire"));
    GameplayTags.Attributes_Resistance_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Resistance.Lightning"));
    GameplayTags.Attributes_Resistance_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Resistance.Arcane"));
    GameplayTags.Attributes_Resistance_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Resistance.Physical"));

    // Map of Damage Types to Resistance
    GameplayTags.DamageTypesToResistances.Add( GameplayTags.Damage_Arcane, GameplayTags.Attributes_Resistance_Arcane);
    GameplayTags.DamageTypesToResistances.Add( GameplayTags.Damage_Lightning, GameplayTags.Attributes_Resistance_Lightning);
    GameplayTags.DamageTypesToResistances.Add( GameplayTags.Damage_Physical, GameplayTags.Attributes_Resistance_Physical);
    GameplayTags.DamageTypesToResistances.Add( GameplayTags.Damage_Fire, GameplayTags.Attributes_Resistance_Fire);

    GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Effects.HitReact"));
}