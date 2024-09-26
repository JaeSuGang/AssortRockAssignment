// 047_ClassOperator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
public:
    // Player()    {    }

    // 여러분들이 만들지 않아도 컴파일 그냥 자동으로 만들어줬다.
    //Player(const Player& _Other)
    //    : Hp(_Other.Hp) // 초기화
    //{
    //    // _Other.Hp = 0;
    //    Hp = _Other.Hp; // 대입
    //}

    // 과거에 막는 방식
public:
    // 디폴트 대입 연산자
    // operator =(연산자)
    // 최적화에서 복사는 가장 많은 연산량이 필요한 함수입니다.
    // 안하면 안할수록 좋다.(해야할때는 해야죠)

// private: // <= 옛날에 복사가 벌어지는걸 감지하는 방법
    // 이 함수 사용안할께 14버전부터 가능한 방법.
    // Player& operator=(const Player& _Other) = delete; 
    //{
    //    // 값대 값 복사로 맴버변수를 그대로 대입하는 연산을 합니다.
    //    Hp = _Other.Hp;
    //    return *this;
    //}

    // constrcuter destructer

    // 여러분들이 아무것도 안해도 생기는 것들
    Player() {}
    ~Player() {}

    // delete Function
    Player(const Player& _Other) = delete;
    // 자료구조를 배워야 Player&& RValue 레퍼런스는 나중에.
    Player(Player&& _Other) noexcept = delete;
    Player& operator=(const Player& _Other) = delete;
    Player& operator=(Player&& _Other) noexcept = delete;
    

    int operator<(const Player& _Other)
    {
        return 10;
    }

    int operator*()
    {

    }

    // 함수객체 
    int operator()()
    {

    }


    int Hp = 0;
};

class Monster
{
public:
    Monster operator+(const Monster& _Other)
    {
        return Monster();
    }
};

// 수학관련 클래스가 보통 연산자 겹지정을 하지
// 몬스터 플레이어 이런애들은 연산자 겹지정을 하지 않아요.
class Vector3 {

};

int main()
{
    Player NewPlayer0;
    Player NewPlayer1;

    int Value0 = NewPlayer0 < NewPlayer1;

    int Value1 = NewPlayer0.operator<(NewPlayer1);

    // 복사 생성자
    // Player NewPlayer1 = NewPlayer0;
    // Player NewPlayer2;

    // 연산자 겹지정이란 함수호출을 마치 연산자 처럼도 쓸수 있게 해주는 문법이다.
    // NewPlayer1 = NewPlayer2;
    // NewPlayer1.operator=(NewPlayer2);



    // NewPlayer + NewPlayer;

    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
