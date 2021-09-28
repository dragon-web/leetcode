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

//然后对字符串从左到右来，
//如果当前字符代表的值不小于其右边，就加上该值；否则就减去该值。 MCMXCIV 1994  1000 - 100 + 1000 - 10 + 100 - 1 + 5
//以此类推到最左边的数，最终得到的结果即是答案

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
                // 多余的右括号是不需要的，标记
                if (st.empty())
                    mark[i] = 1;   //标记多余右括号
                else st.pop();
            }
        }
        // 未匹配的左括号是不需要的，标记
        while (!st.empty()) {
            mark[st.top()] = 1;
            st.pop();
        }
        // 寻找标记与标记之间的最大长度
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
     Person(const string& nm = string("xxx")) :name(nm), id(0) {} //就不用默认无参构造了 ；隐式转换

public:
    bool isSamePerson(const Person& person) const { //const成员函数 ，只能调用const成员（变量、函数）！
        cout << "比较对象：" << person.getId() << "--" << person.getName() << endl;//
        return id == person.getId(); //
    }

    const int& getId() const { //任意一个const去掉后，都会导致问题。。。 
        return id;
    }
    const string& getName() const { //因为const修饰的是this指向的对象，所以也必须返回const引用
        return name;
    }
};

int main() {
    string a = "aaa";
    Person p1(a);
    cout << p1.getId() << "--" << p1.getName() << endl;

    string b = "bbb";
    cout << p1.isSamePerson(b) << endl; //隐式转换！！！ 

    return 0;
}