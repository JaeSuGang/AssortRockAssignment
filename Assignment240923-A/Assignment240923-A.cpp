#include <iostream>

int StringCount(const char* const lpszData)
{
	int nCharCount = 0;

	while (lpszData)
	{
		if (lpszData[nCharCount] == '\0')
		{
			break;
		}

		nCharCount++;
	}

	return nCharCount;
}

int main()
{
	int nCharCount = StringCount("dddfsafsadd");
	printf("%d\n", nCharCount);
}

