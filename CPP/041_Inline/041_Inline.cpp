// 041_Inline.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player
{
public:
    // 명시해주는것이 좋다.
    inline void Test()
    {
        std::cout << "뭘한건가요?" << std::endl;
    }

    // 컴파일러야 판단하지마
    // 무조건 복붙해서 함수호출 하지마.
    // 계산하지마 만들어
    __forceinline void Test000()
    {
        std::cout << "뭘한건가요?" << std::endl;
    }

};

inline int Test() // 함수 선언 function head
{ // 함수 체(몸통) function body
    // 내부에서 자신만의 메모리를 가질이유가 없다.
    std::cout << "뭘한건가요?" << std::endl;
}

int main()
{
    // Test();
    // std::cout << "뭘한건가요?" << std::endl;
    // 함수 호출을 삭제하고 
    // 가능하다면 함수 호출을 삭제하고
    // 함수 몸통을 복붙하는 문법이다

    Player Test;

    std::cout << "뭘한건가요?" << std::endl;

    std::cout << "Hello World!\n";
}
