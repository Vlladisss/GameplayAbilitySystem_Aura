// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{

    const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

    OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
    OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());

    OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
    OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
    const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

    // Get Attributes in Delegate***************
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        AuraAttributeSet->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data) {
        OnHealthChanged.Broadcast(Data.NewValue);
    });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        AuraAttributeSet->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data) {
        OnMaxHealthChanged.Broadcast(Data.NewValue);
    });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        AuraAttributeSet->GetManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data) {
        OnManaChanged.Broadcast(Data.NewValue);
    });

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        AuraAttributeSet->GetMaxManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data) {
        OnMaxManaChanged.Broadcast(Data.NewValue);
    });

    Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->OnEffectAssetTagsDelegate.AddLambda(
        [](const FGameplayTagContainer& AssetTags) {

            for (const FGameplayTag& Tag : AssetTags)
            {
                //TODO: Broadcast the tag to the Widget Controller
                const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
                GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);
            }
        }
        );
}


