#include "HealthComponent.h"

void UHealthComponent::TakeDamage(int nDamage)
{
	m_nHealth -= nDamage;
}
