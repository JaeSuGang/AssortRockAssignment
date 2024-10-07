#include "BlackSmith.h"
#include "Weapon.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("부모존이 세팅되지 않았습니다");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. 강화\n";
		std::cout << "2. 나간다\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
			DoUpgradeTry(_Player);
			// 확률은 전부다 2분의 1
			// 1돈이 깎여야 한다. 플레이어의 강화 단계 * 100
			// 내가 현재 5강에 도전하고 있다. 그러면 500원씩 깍여야 한다.
			// 1~5까지는 실패가 실패확률은 있지만.
			// 다운되지는 않는다.
			// 6~10까지는 실패하면 1씩 다운된다.
			// 10~15는 0으로 실패하면 0으로 떨어진다.
			// 15강 이상이면 강화를 못하게 해야해한다.
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

	printf("+%d강에 성공했습니다!!\n", HoldingWeapon->GetUpgradeCount());
	_getch();


}

void BlackSmith::DoUpgradeFailure(UPlayer& _Player)
{
	Weapon* HoldingWeapon = _Player.GetHoldingWeapon();

	int nBeforeUpgradeCount = HoldingWeapon->GetUpgradeCount();

	if (nBeforeUpgradeCount < 5)
	{
		printf("강화에 실패했습니다.. 현재 +%d강\n", HoldingWeapon->GetUpgradeCount());
		_getch();
	}
	else if (nBeforeUpgradeCount < 10)
	{
		HoldingWeapon->SetUpgradeCount(nBeforeUpgradeCount - 1);
		printf("강화에 실패했습니다.. 현재 +%d강\n", HoldingWeapon->GetUpgradeCount());
		_getch();
	}
	else if (nBeforeUpgradeCount <= 15)
	{
		HoldingWeapon->SetUpgradeCount(0);
		printf("강화에 실패했습니다..  무기 강화 수치가 초기화되었습니다.\n", HoldingWeapon->GetUpgradeCount());
		_getch();
	}
}
