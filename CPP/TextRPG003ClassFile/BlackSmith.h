#pragma once
#include "Zone.h"

class BlackSmith
{
public:
	// �ȳ־��ָ� ������ �ȵ�.
	//BlackSmith(UZone& _ParentZone)
	//	: ParentZone(_ParentZone)
	//{

	//}

	void InPlayer(class UPlayer& _Player/*, int& Result*/);

	inline void SetParent(class UZone* _ParentZone)
	{
		ParentZone = _ParentZone;
	}

protected:
	bool DoUpgradeTry(class UPlayer& _Player);

	void DoUpgradeSucess(class UPlayer& _Player);

	void DoUpgradeFailure(class UPlayer& _Player);

private:
	// class UZone& ParentZone;

	class UZone* ParentZone = nullptr;
};

