#include <iostream>

int StringCount(const char* const lpszData)
{
	int nCharCount = 0;

	while (lpszData[nCharCount])
	{
		nCharCount++;
	}

	return nCharCount;
}

int main()
{
	int nCharCount = StringCount("dddfsafsadd");
	printf("%d\n", nCharCount);
}

