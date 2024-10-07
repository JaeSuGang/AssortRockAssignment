
#include <iostream>
#include "TestClass.h"

// 선언의 핵심은 내 눈에 보이기만 해도 선언 된것이다.
// 구현의 핵심은 실행되거나 메모리화가 되어야 구현

// 선언과 구현은 어떻게 되는가?
// 자료형
// 전역함수
// 객체

// 선언 선생님이 집중해서 보는것.
// 한파일내에서 선언 중복이 되는것과 안되는 녀석이 있다.
// 한파일이 아니라면 선언은 언제나 중복이 가능하다.

// 자료형의 선언과 구현에 대한 이해
// 클래스는 구현이라는 개념이 없다.
class Player
{
    // 자료형안에 어떤 기능이 있다면 그걸 구현해줘야 한다.

public:
    // 맴버함수의 구현이지 클래스의 클래스의 구현이 아니다.
    void Test()
    {
    }

    int a = 0;
};


// 함수의 선언과 구현에 대한 이해
void Test();

// 객체의 선언과 구현에 대한 이해
// 이 객체도 선언과 구현이 분리
// 초기화를 하지 않으면 선언이 된다.
// extern Player NewPlayer = 0;
extern int NewPlayer;
// 주의해야할게 뭡니까?

// extern int NewPlayer = 0;

// 객체는 선언과 구현을 분리하지 않으면
int A = 0;

int main()
{
    TestClass NewClass;
    std::cout << "Hello World!\n";
}
