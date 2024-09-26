#pragma once
#include <vector>
#include <type_traits>
#include "ActorComponent.h"

using namespace std;

class UActorComponent;

class AActor
{
public:
	virtual vector<UActorComponent*> GetComponents();
	template<typename T>
	void AddComponent();

public:
	virtual ~AActor();

protected:
	vector<UActorComponent*> m_ComponentArray;

};

template<typename T>
inline void AActor::AddComponent()
{
	static_assert(is_base_of<UActorComponent, T>::value);
	T* Component = new T(this);
	m_ComponentArray.push_back(Component);
}
