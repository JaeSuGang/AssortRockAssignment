#include <iostream>

void* Foo()
{
	return new char****{};
}

int main()
{
	void* A = Foo();

	A = static_cast<int*>(100);

}

