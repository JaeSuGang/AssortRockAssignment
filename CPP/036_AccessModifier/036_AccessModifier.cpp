// 036_AccessModifier.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 클래스 내부에는 여러분들이
// 직접 안해주면 자동으로 들어가는 것들이 몇가지 있는데.
// 그중 접근제한 지정자기는 디폴트로 private으로 되어있다.
class Player
{
// private: <= 외부에 공개하지 않겠다.
// public: 외부에 공개하겠다.
// protected: <= 자식내부에도 공개하겠다.

// 여기 제외는 다 외부이다.
// private: <= 디폴트 접근제한 지정자 생략되어있다.
// 패가 망신
    int Hp;
    int Att;
    void Attack()
    {
        Hp = 20;
    }

    Player()
    {
    }

    //public: // 디폴트 생성자
    //    Player()
    //    {
    //    }
};

// 업계 기본 
// 아주 드문경우가 특정 상황에서는 
// public 맴버변수도 사용할껍니다.

// 맴버변수는 공개하지 않고
// 맴버함수 일부는 공개하는게 기본인데.

//class Monster
//{
//public:
//    void Damage()
//    {
//        Player NewPlayer;
//        NewPlayer.Att; // 외부
//    }
//};

// 
// 공간 4가지
//                    클래스의 입장
// class Player
// {
//     int Hp;
// }

// Hp의 입장에서 생각해보자.
// 1. 전역             외부
// 2. 지역             외부
// 3. 클래스 내부       내부
// 4. 다른 클래스 내부  외부
// 5. 자식 클래스 내부  외부

int Value;
Player NewPlayer;
// NewPlayer.Hp; <= 외부

int main()
{
    Player NewPlayer = Player();
    // NewPlayer.Hp <= 외부
}
