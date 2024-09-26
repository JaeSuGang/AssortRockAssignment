#include "Actor.h"
#include "AttackComponent.h"

void UAttackComponent::Attack(AActor* TargetActor)
{
	auto Components = TargetActor->GetComponents();

	for (UActorComponent* Component : Components)
	{
		UHealthComponent* HealthComponent = dynamic_cast<UHealthComponent*>(Component);

		if (HealthComponent)
		{
			HealthComponent->TakeDamage(m_nDamage);
		}
	}
}
