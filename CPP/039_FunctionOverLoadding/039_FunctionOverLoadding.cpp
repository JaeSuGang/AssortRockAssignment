// 039_FunctionOverLoadding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 모든 영역의 함수에서 동일하게 적용할수 있는 문법입니다.
// 이름은 같은데 인자가 다른 함수들을 여러개 만들수 있는 문법인데.
// 그래도 에러가 안나는 문법이다.
// 컴파일러는 애초에 함수를 이름만으로 인식하지 않고 인자와 함쳐서 하나의 이름으로 봅니다.
// 리턴값은 포함되지 않는다.

// ::Test
void Test()
{
}

// 오버로딩 규칙 첫번째 리턴값은 이름에 포함되지 않는다.
// 리턴값을 바꾼다고 같은 이름의 함수를 오버로딩 할수는 없다.
//int Test()
//{
//    return 10;
//}

// 인자만이 컴파일러의 이름 인식에 영향을 준다.
// ::Test(int)
void Test(int _Value)
{
}

// Test(char)
void Test(char _Value)
{
}

// TestCharInt
void Test(char _Value, int Value)
{
}

// TestIntChar
void Test(int _Value, char Value)
{
}

class Player
{
public:
    Player()
    {

    }

    Player(int _Hp, int _Att)
    {

    }

    Player(int _Hp, int _Att, const char* const _Name)
    {

    }
};


int main()
{
    Test('C');

    Test('C', 10);

    Player();
    Player(10, 10);
    Player(10, 10, "aaaaaa");

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
