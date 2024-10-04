// 059_VirtualFunctionPtr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
public:
    virtual int GetAtt()
    {
        return 0;
    }

    virtual int StatusRender()
    {
        return 0;
    }


    int Value = 0;

    FightUnit()
        : Value(100)
    {
        // 생성되면서 가상함수 테이블도 만들어 지겠죠?
        this;
    }
};

class Player : public FightUnit
{
public:
    // virtual을 붙이는 순간
    // 갑자기 클래스의 크기가 8이 됐다.
    // ?????????????????????
    // 8은? 포인터의 크기
    void TestFunction()
    {

    }

    int GetAtt() override
    {
        return 0;
    }

    Player()
        : FightUnit()
    {
        // FihgtUnit 가 먼저 Value
        // 플레이어는 Value가 만들어지고 사용할수 있으니까 Value를 사용한다.
        Value = 20;
        this;
    }
};

int main()
{
    Player NewPlayer = Player();

    int SizePlayer = sizeof(Player);


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
