#include <Windows.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;
/*
class Solution {
public:
    map<char, int> M = { make_pair<char,int>('I',1),make_pair<char,int>('V',5),make_pair<char,int>('X',10),make_pair<int,char>('L',50),make_pair<char,int>('C',100),make_pair<char,int>('D',500),make_pair<char,int>('M',1000) };
    int romanToInt(string s) {
        if (s.size() == 1)
        {
            if (M.find(s[0]) != M.end())
            {
                return M[s[0]];
            }
        }
        else {
            return -1;
        }
        int res = 0;
        for (size_t i = 0; i < s.size() - 1; ++i)
        {
          
            if (M[s[i]] >= M[s[i+1]])
            {
                res += M[s[i]];
            }
            else
            {
                res -= M[s[i]];
            }
        }
        return  res;
    }

};

//Ȼ����ַ�������������
//�����ǰ�ַ������ֵ��С�����ұߣ��ͼ��ϸ�ֵ������ͼ�ȥ��ֵ�� MCMXCIV 1994  1000 - 100 + 1000 - 10 + 100 - 1 + 5
//�Դ����Ƶ�����ߵ��������յõ��Ľ�����Ǵ�

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> mark(s.length(),0);
        int left = 0, len = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                // ������������ǲ���Ҫ�ģ����
                if (st.empty())
                    mark[i] = 1;   //��Ƕ���������
                else st.pop();
            }
        }
        // δƥ����������ǲ���Ҫ�ģ����
        while (!st.empty()) {
            mark[st.top()] = 1;
            st.pop();
        }
        // Ѱ�ұ������֮�����󳤶�
        for (int i = 0; i < s.length(); i++) {
            if (mark[i]) {
                len = 0;
                continue;
            }
            len++;
            ans = max(ans, len);
        }
        return ans;
    }
};
int main()
{
    map<char, int> M = { make_pair<char,int>('I',1),make_pair<char,int>('V',5),make_pair<char,int>('X',10),make_pair<int,char>('L',50),make_pair<char,int>('C',100),make_pair<char,int>('D',500),make_pair<char,int>('M',1000) };
    cout << M['I'];
    system("pause");
    return 0;
}
*/


#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int id;

public:
     Person(const string& nm = string("xxx")) :name(nm), id(0) {} //�Ͳ���Ĭ���޲ι����� ����ʽת��

public:
    bool isSamePerson(const Person& person) const { //const��Ա���� ��ֻ�ܵ���const��Ա����������������
        cout << "�Ƚ϶���" << person.getId() << "--" << person.getName() << endl;//
        return id == person.getId(); //
    }

    const int& getId() const { //����һ��constȥ���󣬶��ᵼ�����⡣���� 
        return id;
    }
    const string& getName() const { //��Ϊconst���ε���thisָ��Ķ�������Ҳ���뷵��const����
        return name;
    }
};

int main() {
    string a = "aaa";
    Person p1(a);
    cout << p1.getId() << "--" << p1.getName() << endl;

    string b = "bbb";
    cout << p1.isSamePerson(b) << endl; //��ʽת�������� 

    return 0;
}