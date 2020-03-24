#define _CRT_SECURE_NO_WARNINGS 
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>Add(nums1.begin(),nums1.end());
		Add.insert(Add.end(),nums2.begin(), nums2.end());
		sort(Add.begin(), Add.end());
		if (Add.size() % 2 == 0)
		{
			return (double)(((Add[(Add.size() / 2)] + Add[(Add.size() / 2 - 1)]))/2.0);
		}
		else
			return (double)(Add[(Add.size() / 2)]);
	}
};
int main()
{
	Solution A;
	int arr[6] = { 1,2,3,4,5,6 };
	std::vector<int> v1(&arr[0], &arr[3]);
	std::vector<int> v2(&arr[3], &arr[6]);
	double answer = A.findMedianSortedArrays(v1, v2);
	cout << answer << endl;
	system("pause");
	return 0;
}


