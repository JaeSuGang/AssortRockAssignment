// 046_Define.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <assert.h>
#include <Windows.h>

// #이 붙어있으므로 전처리문
// 빌드 단계중 전처리기가 처리하는 문장입니다.

// 복붙
// 전처리문은 ;을 통해서 구문 마침을 명시할 필요가 없다.

// 심지어     공백도 컨트롤 CV합니다.
// #define 한 녀석때문에 에러가 났으면 
// 무조건 CV입니다. 그러니까 그대로 CV 에러가 날 코드가 됩니다.
// C스타일 문법이기 때문에 저는 거의 사용하지 않습니다.
// 아주 긴 문장을 축약하고 싶을때 사용합니다.

// 역슬레시를 하면 여러줄의 문장을 복사할수도 있습니다.
// 가독성이 떨어진다.
// 여백하나도 틀리면 틀릴수 있다.

#define ERRORPRINT \
MessageBoxA(nullptr, "치명적인 에러입니다 코드를 확인해주세요", "치명적 에러", MB_OK); \
assert(false); 

// 이걸 메크로 함수라고 합니다.
// 매크로 인자 명 => TEXT
// 1. 단계 먼저 매크로 인자를 복붙 현재 보이는 #define 에 복붙한다.
// 2. 그 문장을 다시 복붙

#define ERRORPRINTSTR(VALUE) \
MessageBoxA(nullptr, VALUE, "치명적 에러", MB_OK); \
assert(false); 


#define MUL(VALUE) VALUE * VALUE
#define SUM(VALUE) VALUE + VALUE


// 언리얼은 #define을 좀 많이 사용합니다.
// 가독성이 떨어진다 => 디버깅이 힘들다.
// #define 

// 


// typedef 는 자료형만 가능한데.

int main()
{
    // 안읽힌다.
    // int Value = MUL(SUM(10));

    int Value = 10 + 10 * 10 + 10;

    // ERRORPRINTSTR("에러가 날겁니다");


    //MessageBoxA(nullptr, "에러가 날겁니다", "치명적 에러", MB_OK); \
    //    assert(false);


    // MessageBoxA(nullptr, "치명적인 에러입니다 코드를 확인해주세요", "치명적 에러", MB_OK); 
    // assert(false);

    // AAA TestValue;
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
