#pragma once
#include "Actor.h"

class AActor;

class UActorComponent
{
public:
	virtual AActor* GetOwner();


public:
	UActorComponent(AActor* Owner);
	virtual ~UActorComponent() = default;

protected:
	AActor* m_Owner;
};