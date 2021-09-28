#include <iostream>
#include <vector>

using namespace std;

template<class T1, class T2>

auto Add(const T1 & a ,const T2& b)->decltype(a+b)
{
	return a + b;
}



int main()
{
	const static int a = 10;
	a = 11;
	cout << Add(1,3.12) << endl;
	return 0;
}
