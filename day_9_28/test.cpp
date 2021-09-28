#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

/*
template<typename T , size_t N>
class Test
{
public:
	Test()
	{
		for (size_t i = 0; i < N; ++i)
		{
			elements[i] = i;
		}
	}
	~Test()
	{}
	T* begin()
	{
		return elements + 0;
	}
	T* end()
	{
		return elements + N;
	}
private:
	T elements[N];
};

int main()
{
	Test<int, 3> tes;
	for (auto& it : tes)
	{
		it = 2;
	}
	for (auto& it : tes)
	{
		cout << it << endl;
	}
	system("pause");
	return 0;
}
*/


class A {
public : 
	int num1;
public:
	int Initnum(int num)
	{
		num1 = num;
		return 0;
	}
};

int main()
{

	A a;
	a.Initnum(1);

	system("pause");
	return 0;
}