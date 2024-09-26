#pragma once
#include "Actor.h"
#include "ActorComponent.h"

class UHealthComponent : public UActorComponent
{
public:
	void TakeDamage(int nDamage);

private:
	int m_nHealth;
};