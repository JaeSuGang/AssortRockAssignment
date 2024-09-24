#include <iostream>

#define NUMBER_TO_ASCII(n) n + 0x30

int GetDigit(int nInputData);
int GetNumberAtDigit(int nInputData, int nTargetDigit);
void NumberToString(char* lpszBuffer, int nSize, int nInputValue);

int GetDigit(int nInputData)
{
    int nDigit{};

    while (nInputData)
    {
        nInputData = nInputData / 10;
        nDigit++;
    }

    return nDigit;
}

int GetNumberAtDigit(int nInputData, int nTargetDigit)
{
    int nResult = nInputData;

    for (int i = 1; i < nTargetDigit; i++)
    {
        nResult = nResult / 10;
    }

    nResult = nResult % 10;

    return nResult;
}

void NumberToString(char* lpszBuffer, const int nSize, const int nInputValue)
{
    const int nTotalDigit = GetDigit(nInputValue);
    int nCurrentDigit = nTotalDigit;

    for (int i = 0; i < nTotalDigit; i++)
    {
        nCurrentDigit = nTotalDigit - i;
        lpszBuffer[i] = NUMBER_TO_ASCII(GetNumberAtDigit(nInputValue, nCurrentDigit));
    }

    return;
}

int main()
{
    // 5
    int Result0 = GetDigit(12358);
    // 4
    int Result1 = GetDigit(5258);
    // 7
    int Result2 = GetDigit(5258111);

    // 0은 영

    char Buffer[100] = { 0 };

    NumberToString(Buffer, 100, 371222);
    // Buffer == "3712"

    std::cout << Buffer;
}

