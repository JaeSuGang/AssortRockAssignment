// 015_Pointer002.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test(int Value0, int Value1, int Value2, int Value3)
{
    int* Ptr = &Value0;
    int TestValue0 = *Ptr;

    int TestValue1 = Value1;
    int TestValue2 = Value2;
    int TestValue3 = Value3;

    int a = 0;
}

int A;
// ::A

int main()
{
    Test(10, 20, 30, 40);

    // 일반적으로 지역변수의 이름은 같은 이름을 사용할수 없어요
    // 같은 이름의 변수는 같은 영역내에서 2개가 선언될수 없습니다.
    // 이유는 같은 위치에 변수가 2개의 의미를 가지게 되어야 한다는 것이고

    // ::main::A
    int A = 20;
    int B = 50;

    // int A;
    // A가 2개라면 2개의 A중 누구를 수정하려고 했는지에 대해서 알수가 없는 상황이온다.
    // A = 0;

    // 100번지에 존재하는 int를 가리키는 녀석이 되었습니다.
    // 포인터는 주소 이동이 됩니다.
    int* APtr = &A;
    int* BPtr = &B;

    // 이름없는 스택
    {
        // ::main::AddRess
        __int64 AddRess = reinterpret_cast<__int64>(APtr);
        __int64 AddRessB = reinterpret_cast<__int64>(BPtr);

        // 100번지에 있으면
        //int A = 20;
        // 132번지에 있다.
        //int B = 50;

        int* TestBPtr = APtr + 8;
        *TestBPtr = 15645645;
        int a = 0;
    }

    {
        APtr = APtr + 2;
        // APtr이 100번지라고 한다면
        // APtr = 100 + sizeof(int) * 2;
        // ::main::AddRess
        __int64 AddRess = reinterpret_cast<__int64>(APtr);
        // 결과는 108번지가 나와야 합니다.
        int a = 0;
    }

    {
        APtr = APtr - 2;
        // APtr = 100 - sizeof(int) * 2;
        // ::main::AddRess
        __int64 AddRess = reinterpret_cast<__int64>(APtr);
        int a = 0;
    }

    std::cout << "Hello World!\n";
}
