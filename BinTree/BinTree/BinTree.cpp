#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>

using namespace std;



/*int main()
{
	vector<int>temp;
	
	temp.push_back(2);
	temp.push_back(5);
	temp.push_back(7);
	temp.pop_back();
	vector<int>::iterator it = temp.end();
	cout << *(it-1) << endl;
	system("pause");
	return 0;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (root != NULL)
		{
			vector<int> temp;
			temp.push_bank(root->val);
			while (!temp.empty())
			{
				vector<int>::iterator it = temp.end();
				cout << *(it - 1);
				temp.pop_back();

				if (root->right != NULL)
				{
					temp.push_bank(root->right->val);
				}
				if (root->left != NULL)
				{
					temp.push_bank(root->left->val);
				}
			}
			return temp;
		}


	}
};
*/
//��ʧ�ܵĲ�Ʒ�������ֻ��һ��vector<>ȥʵ�ֱ������ͻ�������root�޷��ҵ��������Ԫ�ؽ��б���
