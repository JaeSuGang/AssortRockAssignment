// 045_TypedefAndUsing.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>

// unsigned __int64를 앞으로는 size_t라고 부르겠다.
typedef unsigned __int64 TestInt;

typedef TestInt MyTestInt;

// 클래스는 아래와 같이 사용하는 경우를 볼수가 있다.
// C때의 문법이다. => C++ 에서 쓸수 있으면 안되는 문법이다.
typedef class ____Test
{

} Test;

// C++을 만든 스투룹 선생님은 C++을 만들때
// C가 주력인 사람이었습니다.

// struct Myclass
// 본래 이름을 이상하게 지어
//class __Myclass
//{
//
//};
//
//typedef class __Myclass Myclass;

// 클래스를 class __Myclass선언하면서 class __Myclass 이름을 => Myclass
typedef class __Myclass
{

} Myclass;

// C에서 위와 같이 class Myclass


// 이게 가독성이 떨어진다고 동일한 문법을 하나 더 만들었다.
using MyInt = int;

// 자료형에 별명을 붙이는 겁니다.

// typedef int MyInt;
// 가독성이 떨어지는 문법이 되어버렸다.
// 추후에 배울 여러가지 빌드 상황에서
// 같은 코드로 동작하게 만들려고 재정의 하는 겁니다.

int main()
{
    {
        typedef const char *LPCSTR, *PCSTR;

        CHAR;

        // enf
        // typedef const char * LPCSTR;
        // typedef const char * PCSTR;

        // const char = PCSTR;

        int Size0 = sizeof(PCSTR);
        int Size1 = sizeof(LPCSTR);

        PCSTR Str = "AAAAA";
        LPCSTR Str = "AAAAA";
        
        int a = 0;

        MyInt NewInt;
        TestInt Test;
    }

    {
        // C에서는 Myclass라고 사용할수가 없었다.
        // class Myclass Value;

        int a = 0;
    }

    std::cout << "Hello World!\n";
}
