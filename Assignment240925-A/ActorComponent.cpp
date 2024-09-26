#include "ActorComponent.h"

AActor* UActorComponent::GetOwner()
{
	return m_Owner;
}

UActorComponent::UActorComponent(AActor* Owner)
{
	m_Owner = Owner;
}

