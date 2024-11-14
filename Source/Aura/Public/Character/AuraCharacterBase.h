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
class UAnimMontage;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
    GENERATED_BODY()

public:
    AAuraCharacterBase();
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    virtual UAnimMontage* GetHitReactMontage_Implementation() override;
    virtual void Die() override;

    UFUNCTION(NetMulticast, reliable)
    virtual void MulticastHandleDeath();

    UAttributeSet* GetAttributeSet() const;

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
    virtual void InitializeDefaultAttributes() const;

    void AddCharacterAbilities();


    /*Dissolve Effects*/

    void Dissolve();

    UFUNCTION(BlueprintImplementableEvent)
    void StartDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);

    UFUNCTION(BlueprintImplementableEvent)
    void StartWeaponDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<UMaterialInterface> DissolveMaterialInstance;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TObjectPtr<UMaterialInterface> WeaponDissolveMaterialInstance;

private:
    UPROPERTY(EditAnywhere, Category = "Abilities")
    TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

    UPROPERTY(EditAnywhere, Category = "Combat")
    TObjectPtr<UAnimMontage> HitReactMontage;
};