// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"


#include "Core/AuraAssetManager.h"
#include "Core/AuraGameplayTags.h"
#include "AbilitySystemGlobals.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
    check(GEngine);
    UAuraAssetManager* AuraAssetManager =  Cast<UAuraAssetManager>(GEngine->AssetManager);
    return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();
    FAuraGameplayTags::InitializeNativeGameplayTags();
    UAbilitySystemGlobals::Get().InitGlobalData();
}
