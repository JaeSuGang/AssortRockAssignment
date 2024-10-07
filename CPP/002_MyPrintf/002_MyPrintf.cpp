// 002_MyPrintf.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int NumberCount(int _Value)
{
	int Result = 0;
	while (_Value)
	{
		_Value /= 10;
		Result += 1;
	}
	return Result;
}

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
 	int Count = NumberCount(_Value);

	int MulValue = 1;
	for (int i = 0; i < Count - 1; i += 1)
	{
		MulValue *= 10;
	}

	// 자료형은 의미가 없다는 소리를 선생님이 단다.
	// 해석의 차이 입니다.
	// 8421
	// 0110
	// 위와 같은 2진수를 명시적으로 '문자'로 쓰겠다고 선언하는게
	// char Test;
	// bool* Test0 = reinterprint_cast<bool*>(&Test);
	
	// int Test;
	// char* Ptr = reinterprint_cast<char*>(&Test);

	// 정수 => 6
	// 문자 => 6
	// 아스키 => 7bit 

	for (int i = 0; i < Count; i += 1)
	{
		int CurValue = _Value / MulValue;
		Buffer[i] = CurValue + '0';
		_Value -= CurValue * MulValue;
		MulValue /= 10;
	}

	return;
}

const int IntMaxCount = 10;
const int ParameterInter = 8;

// 함수의 인자는 무조건 8바이트씩 떨어져 있다.
int MyPrintf(const char* const _Ptr, ...)
{
	__int64 FAdd = reinterpret_cast<__int64>(& _Ptr);

	int ChCount = 0;

	while (_Ptr[ChCount])
	{
		char Ch = _Ptr[ChCount];

		if (Ch == '%')
		{
			Ch = _Ptr[ChCount + 1];

			switch (Ch)
			{
			case 'd':
			{
				int* Ptr = reinterpret_cast<int*>(FAdd += ParameterInter);
				int ConvertValue = *Ptr;
				char Arr[IntMaxCount] = {};
				NumberToString(Arr, IntMaxCount, ConvertValue);

				MyPrintf(Arr);
				ChCount += 2;
				break;
			}
			default:
				break;
			}
			// 함수내부에서 자기자신을 다시 호출하는 방식을 사용해볼겁니다.
			// 이걸 재귀함수라고 부릅니다.
		}

		putchar(_Ptr[ChCount]);
		ChCount += 1;
	}

	return ChCount;
}

void ReFunction()
{
	// 잘 종료를 해줘야 한다.
	if (true)
	{
		return;
	}

	ReFunction();
}

int main()
{
	// 321, 312

	MyPrintf("Number : %d %d\n", 3213, 4322);


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
