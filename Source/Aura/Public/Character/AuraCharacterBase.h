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

    // C O M B A T - I N T E R F A C E 
    virtual FVector GetCombatSocketLocation_Implementation() override;
    virtual bool IsDeath_Implementation() const override;
    virtual AActor* GetAvatar_Implementation() override;
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    virtual UAnimMontage* GetHitReactMontage_Implementation() override;
    virtual void Die() override;
    // End C O M B A T - I N T E R F A C E 


    UFUNCTION(NetMulticast, reliable)
    virtual void MulticastHandleDeath();

protected:
    virtual void BeginPlay() override;
    bool bDead = false;

    // W E A P O N
    UPROPERTY(EditAnywhere, Category = "Combat")
    TObjectPtr<USkeletalMeshComponent> Weapon;

    UPROPERTY(VisibleAnywhere, Category = "Combat")
    FName WeaponSocketName = "WeaponHandSocket";

    UPROPERTY(EditAnywhere, Category = "Combat")
    FName WeaponTipSocketName;

    // A B I L I T Y - S Y S T E M 
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


    virtual void InitAbilityActorInfo();
    virtual void InitializeDefaultAttributes() const;

    void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;
    void AddCharacterAbilities();
    UAttributeSet* GetAttributeSet() const;
    //**End Ability System **//


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