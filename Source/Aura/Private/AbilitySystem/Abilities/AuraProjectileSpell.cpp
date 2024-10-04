// Vladyslav Kliukin (Gameplay Ability System) Project: "Aura"


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "Actor/AuraProjectile.h"
#include "Interaction/CombatInterface.h"


void UAuraProjectileSpell::SpawnProjectile()
{
    
    const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
    if (!bIsServer || !GetWorld()) return;

    if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo()))
    {                                   
        const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();

        FTransform SpawnTransform;
        SpawnTransform.SetLocation(SocketLocation);
        //TODO: Set the Projectile Rotation

        AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
            ProjectileClass,                            //
            SpawnTransform,                             //
            GetOwningActorFromActorInfo(),              //
            Cast<APawn>(GetOwningActorFromActorInfo()), //
            ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

        Projectile->FinishSpawning(SpawnTransform);
    }
}

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                           const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

 

}
