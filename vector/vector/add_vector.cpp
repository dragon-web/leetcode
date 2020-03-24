#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char **argv)
{
	int arr[6] = { 1,2,3,4,5,6 };
	std::vector<int> v1(&arr[0], &arr[3]);
	std::vector<int> v2(&arr[3], &arr[6]);
	  std::vector<int> v3;
	  v3.insert(v3.end(), v1.begin(), v1.end());
	  v3.insert(v3.end(), v2.begin(), v2.end());
	  for (size_t i = 0; i < v3.size(); i++)
		     {
		         std::cout << v3[i] << ", "; 
		     }
	  vector<int>::const_iterator it = v3.begin();
	  cout << *it << endl;
	  vector<int>::const_iterator i = v3.end();
	  cout << *(i-1) << endl;
	  std::cout << std::endl;
	  system("pause");
		return 0;
}