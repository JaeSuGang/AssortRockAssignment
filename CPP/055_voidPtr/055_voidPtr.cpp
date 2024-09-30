// 055_voidPtr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


//struct Test
//{
//
//};

void Test(void* _Value)
{
    std::cout << "주소출력 void 포인터 : " << _Value << std::endl;
}
//
//void Test(char* _Value)
//{
//    std::cout << "주소출력 char 포인터 : " << _Value << std::endl;
//}
//
//void Test(short* _Value)
//{
//    std::cout << "주소출력 char 포인터 : " << _Value << std::endl;
//}

// 크기와 상관없이 주소값만의 의미로 사용되는 포인터 void*


int main()
{
    // 여러가지 자료형이 존재하면
    // 그 자료형의 포인터들은 각자 호환이 되지 않는다.

    int iPtr = 10;
    char cPtr = 'c';

    Test(&iPtr);
    Test(&cPtr);

    // void* vPtr = iPtr;

    // 일반 포인터 연산이 되지 않는다.
    // void*는 말그대로 순수한 위치의 의미만 가지게 된다.
    // vPtr + 1;
    // 자신의 size를 버린 포인터 오로지 위지만을 가지기 위해서.

    iPtr + 1;
    // iPtr 위치 + sizeof(int) * 1;

    // 나는 말그대로 주소값만 필요한데.
    // C++에서 포인터끼리는 암시적 형변환이 일어날수가 없다.
    // 어떤 포인터이건 void*가 될수 있다.
    // void* _Value

    std::cout << "Hello World!\n";
}
