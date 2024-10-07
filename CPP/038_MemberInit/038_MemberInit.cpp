// 038_MemberInit.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

const int Value = 20;

// 맴버변수 초기화
class Player
{
public:
    // 세팅하고 싶으면 함수 만들면 된다.
    // 이걸로 초기화가 아니다. 만들어지고나서 변경하는 것이다.
    void SettingPlayer(const char* const _Name, int _Hp, int _Att)
    {
        strcpy_s(Name, _Name);
        Hp = _Hp;
        Att = _Att;
    }

    // 같은 이름의 함수가 2개가 있는데.
    // 그냥 잘된다고 생각하면 안되고 함수오버로딩이라는 기능입니다.

    // 과거 방식
    // 맴버 이니셜라이저
    Player() // : Name("Test"), Hp(0), Att(0)
    {

    }
    // 생성자를 1가지만 만들었다.
    // 플레이어를 만들려면 HP와 Att를 무조건 넣어줘야 한다는 것.
    Player(int _Hp, int _Att)
        : Hp(_Hp), Att(_Att)
    {

    }

private:
    // 변수들에 초기값을 넣어주는 방법으로는
    // 리터럴 초기화 C++ 14미만이면 안된다.
    // 회사에서는 못쓸수도 있다.
    char Name[100] = "None";
    int Hp = 100;
    int Att = 10;
};

void Test()
{

}

void Test()
{

}

int main()
{
    // 당연히 안된다.
    //int a = 20;
    //int a = 30;

    // 같은 이름의 함수를 같이 
    Test();

    Player NewPlayer = Player(10, 20);

    Player NewPlayer0 = Player();

    // 권장하지 않았어요.
    int Value = 10; // 리터럴
    Value = 20; // 맴버 이니셜라이저
    int a = 0;
}
