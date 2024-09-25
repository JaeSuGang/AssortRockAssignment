// 040_This.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
public:
	Player(/*Player* const this*/)
	{
		this->Att;
	}

	// 맴버변수의 변화가 있으면 안된다.
	// 맴버함수뒤 const를 붙이면 된다.
	void StatusRender(/*const Player* const this*/) const
	{
		// 이 함수를 호출해도 HP나 ATT같은 메모리에 변화가 없을꺼야.
		// 안심하고 사용해.
		// Hp = 0;
		printf_s("능력치 출력");
	}

	bool IsDeath()
	{
		return Hp <= 0;
	}

	// Player::Damage(Player* const, int)
	void Damage(/*Player* const this,*/ int _Att)
	{
		// this = nullptr;
		Hp -= _Att;
	}

public:
	// ::Player::Hp
	int Hp = 100;
	int Att = 10;
};

// 예약어
// 컴파일 과정에서 사용하지 못하게 막은
// 문법에 근본에 가깝기 때문에 일반유저는 사용하지 못하게 막은 단어들을
// 예약어라고 합니다.
//class class
//{
//};

// 일반적역에서는 안된다.
// this가 없다.
// this는 맴버변수에서만 사용할수 있는 예약어
void Damage(/*Player* this,*/ int _Att) /*const*/
{
	// 객체의 포인터 일경우에는
	// .을 눌러서 하는게 아니다.
	// -> 로 값을 빼내야 한다.
	// _this->Hp -= _Att;
}

int main()
{
	Player NewPlayer0 = Player();
	Player NewPlayer1 = Player();

	NewPlayer0.StatusRender();

	// Player* const NewPlayer0Ptr = &NewPlayer0;
	// NewPlayer0Ptr = nullptr;
	// NewPlayer0Ptr->Hp = 100;


	// 당연히 깍입니다.
	// Damage(&NewPlayer0, 10);
	// Damage(&NewPlayer1, 20);

	// 각 객체가 각자 가지고 있는 Hp를 도대체 어떻게 찾아내서
	// 어떻게 각자 빼줬냐? // 그냥 되는거 아닌가요? => -1000000000000000000000000만점
	NewPlayer0.Damage(/*&NewPlayer0,*/ 10);
	NewPlayer1.Damage(/*&NewPlayer1,*/ 20);

}
