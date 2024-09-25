// 033_Class000_ClassAndObject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 클래스는 모든걸 만들수 있습니다.
// int도 만들수 있습니다.

// 클래스로 만들어진 객체는 모든게 가능하다.
// C++에서 클래스로 뭔가가 안되거나 못해? => 안만들었거나 못만드는 겁니다.
// int bool => 다 클래스입니다.

// C++기본으로 
//class int
//{
//};

class Player
{
public:
    int operator+(const Player& _Other)
    {

    }
};

// class Monster 클래스 선언
// 몬스터는 존재한다.
class Monster
{
    // 내용
    // 몬스터는 도대체 어떤 존재인가?
    // 어떤 행동(함수)을 할수 있는가?
};

int main()
{
    int IntValue;
    IntValue + IntValue;
    Player Player;
    Player + Player; 
    // => 플레이어는 +를 왜 못하죠?
    //    내가 안만들었으니 

    // main이 실행되면 Monster를 하나 만들어야해.
    // 몬스터라고 하는 변수입니다.
    Monster Mon;    // => 실행되었을때 메모리화된 개념을 객체라고 합니다.
}
