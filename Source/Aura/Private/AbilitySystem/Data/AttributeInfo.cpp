// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"


#include "AbilitySystem/Data//AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
    for (const FAuraAttributeInfo& Info : AttributeInformation)
    {
        if (Info.AttributeTag == AttributeTag)
        {
            return Info;
        }
    }

    if (bLogNotFound)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't find info for AttributeTag [%s] on  AttributeInfo [%s]."), *AttributeTag.ToString(), *GetNameSafe(this));
    }

    return FAuraAttributeInfo();

}
