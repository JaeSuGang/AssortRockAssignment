#include "Player.h"
#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include <conio.h>


void UWorld::InPlayer(UPlayer& _Player)
{
	char InputName[100] = {0,};

	while (true)
	{
		system("cls");

		std::cout << "�̸��� �����ּ���" << std::endl;
		std::cin >> InputName;

		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");
		int Select = _getch();
		bool IsEnd = false;
		switch (Select)
		{
		case 'a':
			_Player.SetName(InputName);
			IsEnd = true;
			break;

		case 'A':
			_Player.SetName(InputName);
			IsEnd = true;
			break;

		case 'b':
			IsEnd = false;
			break;

		case 'B':
			IsEnd = false;
			break;
		default:
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n", InputName);
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// �������ʱ��� ���⼭ �� ������� ����
	// ������ ������ FightZone�� ��� �ȴ�.
	// ���� ��� �������� 
	
	// new�� �� ����� �ϴ°ų�?
	// 8�Ⱑ
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}



}