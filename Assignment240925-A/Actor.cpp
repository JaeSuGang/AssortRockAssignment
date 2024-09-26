#include "Actor.h"

vector<UActorComponent*> AActor::GetComponents()
{
    return m_ComponentArray;
}

AActor::~AActor()
{
    for (UActorComponent* Component : m_ComponentArray)
    {
        delete Component;
    }
}


