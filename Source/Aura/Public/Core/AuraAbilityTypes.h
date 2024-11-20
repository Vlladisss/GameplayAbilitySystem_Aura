#pragma once
#include "GameplayEffectTypes.h"

#include "AuraAbilityTypes.generated.h"

USTRUCT(BlueprintType)
struct FAuraGameplayEffectContext : public FGameplayEffectContext
{
    GENERATED_BODY()

public:
    // Set / Get
    bool IsCriticalHit() const
    {
        return bIsCriticalHit;
    }

    bool IsBlockedHit() const
    {
        return bIsBlockedHit;
    }

    void SetIsCriticalHit(bool bInIsCriticalHit)
    {
        bIsCriticalHit = bInIsCriticalHit;
    }

    void SetIsBlockedHit(bool bInIsBlockedHit)
    {
        bIsBlockedHit = bInIsBlockedHit;
    }

    /** Returns the actual struct used for serialization, subclasses must override this! */
    virtual UScriptStruct* GetScriptStruct() const override
    {
        return StaticStruct();
    }

    /** Creates a copy of this context, used to duplicate for later modifications */
    virtual  FAuraGameplayEffectContext * Duplicate() const override
    {
        FAuraGameplayEffectContext* NewContext = new FAuraGameplayEffectContext();
        *NewContext = *this;
        if (GetHitResult())
        {
            // Does a deep copy of the hit result
            NewContext->AddHitResult(*GetHitResult(), true);
        }
        return NewContext;
    }

    /** Custom serialization, subclasses must override this */
    virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess) override;

protected:
    UPROPERTY()
    bool bIsBlockedHit = false;

    UPROPERTY()
    bool bIsCriticalHit = false;
};


template<>
struct TStructOpsTypeTraits<FAuraGameplayEffectContext> : public TStructOpsTypeTraitsBase2<FAuraGameplayEffectContext>
{
    enum
    {
        WithNetSerializer = true, // Включает поддержку сетевой сериализации
        WithCopy = true           // Включает поддержку копирования (например, для Duplicate)
    };
};