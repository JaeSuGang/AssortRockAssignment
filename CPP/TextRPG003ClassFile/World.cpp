#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <BaseSystem/EngineFile.h>

// #include "EngineFile.h"

// #include "..\BaseSystem\EngineFile.h"
// 정석적인 방법은 아닙니다.

// #include < <= 시작하는 외부경로는 크게 2가지 기능의 영향을 받는다.


#include <conio.h>



void UWorld::PlayerNameSelect(class UPlayer& _Player)
{
	// C:\\

	char InputName[100] = { 0, };

	bool IsNameInput = true;

	while (true)
	{
		if (true == IsNameInput)
		{
			system("cls");
			std::cout << "이름을 적어주세요" << std::endl;
			std::cin >> InputName;
		}

		system("cls");
		printf_s("당신의 이름은 %s입니다. 결정하시겠습니까?\n", InputName);
		printf_s("a. 결정\n");
		printf_s("b. 재입력\n");
		int Select = _getch();

		bool IsEnd = true;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			IsEnd = false;
			IsNameInput = true;
			break;
		default:
			IsEnd = false;
			IsNameInput = false;
			printf_s("잘못된 선택입니다. 다시 선택해주세요\n", InputName);
			_getch();
			break;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// 파일 저장

	_Player.SetName(InputName);
}

void UWorld::PlayerZonePlay(class UPlayer& _Player)
{
	UTown TownZone;
	TownZone.SetName("초보마을");

	UFightZone FightZone;
	FightZone.SetName("초보사냥터");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}

}

void UWorld::InPlayer(class UPlayer& _Player)
{
	// 외부기로 헤더만 있고 CPP는 없다. 
	UEngineFile File;

	// 파일이 없을때
	if (true)
	{
		PlayerNameSelect(_Player);
	}
	else 
	{

	}

	

	/*_Player.SetName("TestPlayer");

	PlayerZonePlay(_Player);*/
}