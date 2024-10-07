// 043_HasAIsA.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class StatusUnit
{
public:
    // char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;
    int Charm = 0;

    // 부모는 자식클래스가 뭔지 절대로 알아서는 안된다.
    //void Test(FightUnit& _Test)
    //{
    //}
};

class QuestUnit
{

};

class FightUnit
{
public:
protected:
private:
};

class Player
{
public:
    // 이걸 자유롭게 넣었다 뺐다 할수 있다면
    // 그걸 컴포넌트 구조라고 합니다.
    StatusUnit Status;
    FightUnit Unit;

public:
    void Test()
    {
        Status.Hp;
    }
};

class Monster : public StatusUnit
{
};

int main()
{
    FightUnit FightUnit;
    Player NewPlayer;

    Monster Monster0;
    Monster0.Hp = 20;

    Monster Monster1;
    Monster1.Hp = 50;

    Monster Monster2;
    Monster2.Hp = 100;






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
