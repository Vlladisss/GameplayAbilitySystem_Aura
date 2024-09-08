// Vladyslav Kliukin (Game Ability System) Project: "Aura"


#include "Character/AuraCharacterBase.h"

#include "AbilitySystemComponent.h"


AAuraCharacterBase::AAuraCharacterBase()
{
    PrimaryActorTick.bCanEverTick = false;

    Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
    Weapon->SetupAttachment(GetMesh(), WeaponSocketName);
    Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    


}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

UAttributeSet* AAuraCharacterBase::GetAttributeSet() const
{
    return AttributeSet;
}

void AAuraCharacterBase::BeginPlay()
{
    Super::BeginPlay();
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
}
