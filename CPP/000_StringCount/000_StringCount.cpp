// 000_StringCount.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 지금만들라고 하는 함수들은
// strlen



int StringCount(const char* const _Str)
{
    //char Ch0 = _Str[0];
    //char Ch1 = _Str[1];
    //char Ch2 = _Str[2];
    //char Ch3 = _Str[3];
    //char Ch4 = _Str[4];

    int Count = 0;

    while (true)
    {
        char Ch = _Str[Count];
        if (0 == Ch)
        {
            break;
        }
        Count += 1;
    }

    return Count;
}
int main()
{
    // [B][B][B][B][0]

    // int Count = strlen("ABCD");
    // ABCD0을 다 본다.
    int MyCount = StringCount("ABCD");

    int a = 0;
}
