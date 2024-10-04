#include <iostream>

class temp
{
public:
	~temp()
	{
		std::cout << "¼Ò¸êÀÚ È£Ãâ" << std::endl;
	}
	int a;
};

int main()
{
	temp test = {};

	return 0;
}