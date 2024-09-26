#pragma once
#include "Actor.h"
#include "ActorComponent.h"
#include "HealthComponent.h"

class UAttackComponent : public UActorComponent
{
public:
	void Attack(AActor* TargetActor);

protected:
	int m_nDamage;
};