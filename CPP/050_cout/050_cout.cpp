#include <iostream>

// 프로그래머 여러명이면 이름이 겹칠때가 많다.

// 별명을 붙이는 것을 namespace라고 합니다.

namespace JHK
{
    // ::JHK::Item
    class Item
    {

    };
}

namespace MJS // <= 이 이니셜을 가진 프로그래머가 만든다.
{
    // ::MJS::Item
    class Item
    {

    };

}

namespace MJS 
{
    namespace TTTT 
    {
        namespace PPP 
        {
            int a = 0;
        }
    }
}


class MyCout
{
public:
    MyCout& operator<<(const char* const _Text)
    {
        printf_s(_Text);
        return *this;
    }
};

// 데이터 영역
// ::cout
MyCout cout;

// using namespace std;

int main()
{
    ::MJS::TTTT::PPP::a = 20;

    // 
    // JHK::Item NewTest;

    // std:: => 네임스페이스
    //          C++ 자체에서 지원하는 C++ 만든 사람들이 지원하는 표준은 여기에 포함된다.
    // cout => 전역객체 => 전역변수 => 데이터영역에 존재하는 전역변수
    // <<  => operator<< == 연산자 겹지정

    std::cout << "aaaaaa\n";

    std::cout << "Hello World!\n";
    // cout << "Hello World!" << std::endl;

}
