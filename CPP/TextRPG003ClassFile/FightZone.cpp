#include "FightZone.h"
#include <conio.h>


int UFightZone::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();
	_getch();
	while (true)
	{
		std::cout << "����ĥ �� ����" << std::endl;
		_getch();
	}
}