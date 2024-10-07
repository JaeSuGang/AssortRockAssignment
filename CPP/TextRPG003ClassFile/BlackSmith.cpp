#include "BlackSmith.h"
#include "Weapon.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
			DoUpgradeTry(_Player);
			// Ȯ���� ���δ� 2���� 1
			// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
			// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.
			// 1~5������ ���а� ����Ȯ���� ������.
			// �ٿ������ �ʴ´�.
			// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
			// 10~15�� 0���� �����ϸ� 0���� ��������.
			// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.
			return;
		case '2':
			return;
		default:
			break;
		}
	}
}

bool BlackSmith::DoUpgradeTry(UPlayer& _Player)
{
	Weapon* HoldingWeapon = _Player.GetHoldingWeapon();

	int nRequiredMoney = HoldingWeapon->GetUpgradeCount() * 100;

	if (_Player.GetGold() < nRequiredMoney)
	{
		return false;
	}

	if (HoldingWeapon->GetUpgradeCount() >= 15)
	{
		return false;
	}

	_Player.SetGold(_Player.GetGold() - nRequiredMoney);

	srand(time(nullptr));
	bool bIsSuccess = static_cast<bool>(rand() % 2);

	if (bIsSuccess)
	{
		DoUpgradeSucess(_Player);
	}
	else
	{
		DoUpgradeFailure(_Player);
	}

	return true;
}

void BlackSmith::DoUpgradeSucess(UPlayer& _Player)
{
	Weapon* HoldingWeapon = _Player.GetHoldingWeapon();

	HoldingWeapon->SetUpgradeCount(HoldingWeapon->GetUpgradeCount() + 1);

	printf("+%d���� �����߽��ϴ�!!\n", HoldingWeapon->GetUpgradeCount());
	_getch();


}

void BlackSmith::DoUpgradeFailure(UPlayer& _Player)
{
	Weapon* HoldingWeapon = _Player.GetHoldingWeapon();

	int nBeforeUpgradeCount = HoldingWeapon->GetUpgradeCount();

	if (nBeforeUpgradeCount < 5)
	{
		printf("��ȭ�� �����߽��ϴ�.. ���� +%d��\n", HoldingWeapon->GetUpgradeCount());
		_getch();
	}
	else if (nBeforeUpgradeCount < 10)
	{
		HoldingWeapon->SetUpgradeCount(nBeforeUpgradeCount - 1);
		printf("��ȭ�� �����߽��ϴ�.. ���� +%d��\n", HoldingWeapon->GetUpgradeCount());
		_getch();
	}
	else if (nBeforeUpgradeCount <= 15)
	{
		HoldingWeapon->SetUpgradeCount(0);
		printf("��ȭ�� �����߽��ϴ�..  ���� ��ȭ ��ġ�� �ʱ�ȭ�Ǿ����ϴ�.\n", HoldingWeapon->GetUpgradeCount());
		_getch();
	}
}
