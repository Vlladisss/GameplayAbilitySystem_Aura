// Vladyslav Kliukin (Game Ability System) Project: "Aura"

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UGameplayAbility;
class UGameplayEffect;
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
    GENERATED_BODY()

public:
    AAuraCharacterBase();

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    UAttributeSet* GetAttributeSet() const;

    
    int32 TestNum = 1;

protected:
    virtual void BeginPlay() override;

    virtual void InitAbilityActorInfo();

    UPROPERTY(EditAnywhere, Category = "Combat")
    TObjectPtr<USkeletalMeshComponent> Weapon;

    UPROPERTY(VisibleAnywhere, Category = "Combat")
    FName WeaponSocketName = "WeaponHandSocket";

    UPROPERTY(EditAnywhere, Category = "Combat")
    FName WeaponTipSocketName;

    virtual FVector GetCombatSocketLocation() override;

    UPROPERTY()
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

    UPROPERTY()
    TObjectPtr<UAttributeSet> AttributeSet;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;


    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultVitalAttributes;


    void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;
    void InitializeDefaultAttributes() const;

    void AddCharacterAbilities();

private:
    UPROPERTY(EditAnywhere, Category = "Abilities")
    TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

};