#include <iostream>

class temp
{
public:
	~temp()
	{
		std::cout << "�Ҹ��� ȣ��" << std::endl;
	}
	int a;
};

int main()
{
	temp test = {};

	return 0;
}