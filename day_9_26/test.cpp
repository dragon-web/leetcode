#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
//#include <string>
#include <vector>
#include <set>
#include <string.h>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <windows.h>

//#define INT_MIN -2147483648
using namespace std;

/*
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
//int ans = INT_MIN; 
//int oneSideMax(TreeNode* root)
//{
//	if (root == nullptr) return 0;
//	int left = max(0, oneSideMax(root->left));
//	int right = max(0, oneSideMax(root->right)); 
//	ans = max(ans, left + right + root->val); 
//	cout << max(left, right) + root->val << endl;
//	return max(left, right) + root->val;
//}

int maxPathsum1(TreeNode* root, int& val)
{
	if (root == nullptr)
	{
		return 0;
	}
	int left = max(0,maxPathsum1(root->left, val));
	int right =max(0,maxPathsum1(root->right, val));
	int lrv = left + right + root->val;
	int ret = root->val + max(left, right);
	val = max(val, max(left, right));
	return ret;
}
int maxPathSum(TreeNode* root)
{
	int ans = INT_MIN;
	int ret = maxPathsum1(root ,ans);
	return ret;
}

int main()
{
	TreeNode t1(1);
	TreeNode t2(3);
	TreeNode t3(5);
	TreeNode t4(4);
	t1.left = &t2;
	t2.left = &t3;
	t2.right = &t4;
	oneSideMax(&t1);
	system("pause");
	return 0;
}

bool Judge(int number)
{
    set<int> S;
    for (int i = 1; i <= number; ++i) // 因子去重
    {
        if (number % i == 0)
        {
            S.insert(i);
        }
    }
    for (auto it : S)
    {
        if (it == 1 || it == 2 || it == 3 || it == 5)
        {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}
int nthUglyNumber(int n) {
    int begin = 1;
    int number = 1;
    while (begin < n)
    {
        if (Judge(number))
        {
            cout << "number = " << number << endl;
            begin++;
        }
        number++;
    }
    return number;
}

int main()
{
	/*set<int> vec = { 1,2,3,4 };
	set<int> vec1 = { 1 , 2 , 3, 4 };
	if (vec == vec1)
	{
		cout << " vec1 = vec" << endl;
	}
	else
	{
		cout << "vec1 != vec" << endl;
	}

    nthUglyNumber(10);
	system("pause");
	return 0;
}


class MyString
{
public:
    MyString(const char* p = NULL)
    {

    }
    MyString(const MyString& str)
    {
        m_data = str.m_data;
    }
    MyString& operator = (const MyString &str)
    {
        m_data = str.m_data;
        return *this;
    }

private:
    int m_data;
};



class MyString
{
public:
    MyString(const char* p = NULL)
    {
        if (p != NULL)
        {
            p_data = new char[strlen(p) + 1];
            strcpy(p_data, p);
        }
    }
    MyString(const MyString& str)
    {
        
    }
    MyString& operator = (const MyString& str)
    {
       

    }

private:
    char* p_data;
};


template<class T>
 
class SeqList
{
public:
    SeqList<T>(size_t Cap = 3)
    {
        capacity = Cap;
        size = 0;
        p_data = new T[capacity];
    }
    bool Empty()const
    {
        return size == 0;
    }
    size_t Size()const
    {
        return size;
    }
    size_t Capacity()const
    {
        return capacity;
    }
    void Push_back(const T& value)
    {
        if (size == capacity)
        {
            capacity = 2 * capacity;
            T* p_temp = new T[capacity];
            memcpy(p_temp, p_data, size * sizeof(T));
            delete[] p_data;
            p_data = p_temp;
            p_temp = NULL;
        }
        p_data[size++] = value;
    }
    T& operator[] (size_t n)
    {
        assert(n < size);
        return p_data[n];
    }
    
private:
    T* p_data;
    size_t size;
    size_t capacity;
};

int main()
{
    SeqList<int> S;
    S.Push_back(1);
    cout << "S.size() = " << S.Size() << endl;
    cout << "S.capacity() = " << S.Capacity() << endl;
    S.Push_back(2);
    cout << "S.size() = " << S.Size() << endl;
    cout << "S.capacity() = " << S.Capacity() << endl;
    for (size_t i = 0; i < S.Size(); ++i)
    {
        cout << S[i] << " ";
    }
    S.Push_back(3);
    cout << "S.size() = " << S.Size() << endl;
    cout << "S.capacity() = " << S.Capacity() << endl;
    S.Push_back(4);
    cout << "S.size() = " << S.Size() << endl;
    cout << "S.capacity() = " << S.Capacity() << endl;
    S.Push_back(5);
    cout << "S.size() = " << S.Size() << endl;
    cout << "S.capacity() = " << S.Capacity() << endl;
    for (size_t i = 0; i < S.Size(); ++i)
    {
        cout << S[i] << " ";
    }
    S.Push_back(6);
    S.Push_back(7);
    S.Push_back(8);
    cout << "S.size() = " << S.Size() << endl;
    cout << "S.capacity() = " << S.Capacity() << endl;
    for (size_t i = 0; i < S.Size(); ++i)
    {
        cout << S[i] << " ";
    }
    system("pause");
    return 0;
}


class String
{
public:
    String(const char* p = "")
    {
        if(p == nullptr)
        {
            p = "";
        }
        m_ptr = new char[strlen(p) + 1];
        strcpy(m_ptr,p);
    }
    ~String()
    {
        if(m_ptr != nullptr)
        {
            delete[] m_ptr;
            m_ptr = nullptr;
        }
    }
    String(const String &s)
    {
        m_ptr = new char[strlen(s.m_ptr) + 1];
        strcpy(m_ptr, s.m_ptr);
    }
    String& operator = (const String& s)
    {
        if (this != &s)
        {
            delete[] m_ptr;
            m_ptr = new char[strlen(s.m_ptr) + 1];
            strcpy(m_ptr,s.m_ptr);
        }
        return *this;
    }
    char operator[](size_t num)
    {
        if (num > strlen(m_ptr))
        {
            cout << "越界" << endl;
            return -1;
        }
        return m_ptr[num];
    }
private:
    char* m_ptr;
};


class String
{
private:
    char* m_ptr;
    size_t capacity;
    size_t size;
public:
    typedef char* iterator;
public:
    void Swap(String & str)
    {
        swap(this->capacity, str.capacity);
        swap(this->size, size);
        swap(this->m_ptr, m_ptr);
    }
    String(const char* str = "")
    {
        if (nullptr == str)
            str = "";

        capacity = strlen(str);
        size = capacity;
        str = new char[capacity + 1];
        strcpy(this->m_ptr, str);
    }
    ~String()
    {
        if (m_ptr)
        {
            delete[] m_ptr;
        }
        capacity = 0;
        size = 0;
        m_ptr = nullptr;
    }
    String& operator = (const String & S)
    {
        if (this != &S)
        {
            String StrTemp(S);
            this->Swap(StrTemp);
        }
        return *this;
    }
    String(const String& S)
    {
        String temp(S.m_ptr);
        this->Swap(temp);
    }
    size_t size()const
    {
        return size;
    }
    size_t capacity()const
    {
        return capacity;
    }
    iterator begin()
    {
        return m_ptr;
    }
    iterator end()
    {
        return m_ptr + size;
    }
};


void Print(vector<int> & vec)
{
    for (auto& it : vec)
    {
        cout << it << " ";
    }
}

void TestVector9()
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Print(v);
    cout << endl;
    v.erase(v.begin());
    Print(v);
    cout << endl;
    v.erase(v.begin(), v.begin() + 3);
    Print(v);
    cout << endl;
    //v.erase(v.begin(), v.end()); // v.clear();
    auto it = v.begin();
    while (it != v.end())
    {
        v.erase(it);
        it = v.begin();
    }
}

class Singletom
{


private:
    Singletom(int m_data)
    {
        data = m_data;
    }
private:
    int data;
};

#include <iostream>
#include <vector>

using namespace std;

bool IsPerfectNum(int num)
{
    while (num != 0)
    {
        int temp = num % 10;
        num /= 10;
        if (temp == 1 || temp == 2 || temp == 3)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int num;
    cin >> num;
    vector<int> vec(num,0);
    for (size_t i = 0; i < num; ++i)
    {
        cin >> vec[i];
        if (IsPerfectNum(vec[i]))
        {
            cout << vec[i] << endl;
        }
        else
        {
            while (!IsPerfectNum(vec[i]))
            {
                vec[i]--;
            }
            cout << vec[i] << endl;
        }
    }
    return 0;
}


int Solution(string str)
{
    return (str.size() * (str.size() + 1)) / 2;
}


#include <iostream>
#include <string>

using namespace std;

int getLengthOfLastWord(string str)
{
    if (str.size() == 0)
    {
        return 0;
    }
    int pos = str.rfind(' ');
    if (pos != string::npos)
    {
        return str.size() - pos - 1;
    }
    return str.size();
}
int main()
{
    string str;
    while (getline(cin,str))
    {
        int ret = getLengthOfLastWord(str);
        cout << ret << endl;
    }
    return 0;
}


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        char ch;
        cin >> ch;
        unordered_map<char, int> M;
        for (size_t i = 0; i < str.size(); ++i)
        {
            M[str[i]]++;
        }
        if (M.find(ch) != M.end())
        {
            cout << M[ch] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        transform(word.begin(), word.end(), new_word.begin(), [](char c)->char { return toupper(c); });
    }
    system("pause");
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;


int main()
{
    int N;
    while (cin >> N)
    {
        vector<int> vec(N, 0);
        set<int> S;
        for (size_t i = 0; i < vec.size(); ++i)
        {
            cin >> vec[i];
            S.insert(vec[i]);
        }
        for (auto it : S)
        {
            cout << it << endl;
            cout << typeid(it).name() << endl;
        }
    }

    return 0;
}
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        int bit = 0;
        int ans = 0;
        for (int i = s.length() - 1; i > 1; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
                ans += (s[i] - '0') * pow(16, bit++);
            else if (s[i] >= 'A' && s[i] <= 'F')
                ans += (s[i] - 'A' + 10) * pow(16, bit++);
        }
        cout << ans << endl;
    }
    return 0;
}
#include<iostream>
#include<string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;
    getchar();
    vector<int> vec(num, 0);
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cin >> vec[i];
        vec[i] = vec[i] / 2;
    }
    sort(vec.begin(), vec.end());
    for (auto it : vec)
    {
        cout << it << endl;
    }
    return 0;
}



int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n, 0);
    for (size_t i = 0; i < A.size(); ++i)
    {
        cin >> A[i];
    }
    if(n == k)
    {cout <<  }

    system("pause");
    return 0;
}




#include<iostream>
#include<string>
#include <vector>
#include <functional>
#include <algorithm>

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> vec(100, 0);
    vector<int> vec1(100, 0);
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < vec.size(); ++j)
        {
            if (j != 0 && j >= vec[0])
            {
                break;
            }
            cin >> vec[j];
        }
    }
    for (size_t i = 0; i < q; ++i)
    {
        for (size_t j = 0; j < vec.size(); ++j)
        {
            if (j != 0 && j >= vec1[0])
            {
                break;
            }
            cin >> vec1[j];
        }
    }
      int num;
    while (cin >> num)
    {
        bitset<100> bt(num);
        cout << bt.count() << endl;
    }
    system("pause");
    return 0;
}



#include<iostream>
#include<string>
#include <vector>
#include <functional>
#include <algorithm>
#include <bitset>

using namespace std;

int GetReferenceValue(int arr[],int left,int right)
{
    int begin = left;
    int end = right - 1;  // 因为传过来的是size 所以要减1
    int key = arr[end];
    while (begin < end)
    {
        while(begin < end && arr[begin] <= key)
        {
            begin++;
        }
        while (begin < end && arr[end] >= key)
        {
            end--;
        }
    }
    if (begin < end)
    {
        swap(arr[begin], arr[end]);
    }
    if (begin != right - 1)
    {
        swap(arr[begin], arr[right - 1]);
    }
    return begin;
}
void Quick_Sort(int arr[],int left,int right)
{
    if (right - left > 1)
    {
        int div = GetReferenceValue(arr, left, right);
        GetReferenceValue(arr,left,div);
        GetReferenceValue(arr, div + 1, right);
    }
}

void Print(int* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
}
int GetReferenceValue(int* arr,int left , int right)
{
    int begin = left;
    int end = right - 1;
    int key = arr[begin];
    while (begin < end)
    {
        while (begin < end && arr[end] >= key)
        {
            end--;
        }
        if (begin < end)
        {
            swap(arr[begin], arr[end]);
            begin++;
        }
        while (begin < end && arr[begin] <= key)
        {
            begin++;
        }
        if (begin < end)
        {
            swap(arr[begin],arr[end]);
            end--;
        }
    }
    cout << "begin = " << begin << endl;
    return begin;
}

void Quick_Sort(int* arr ,int left , int right)
{
    if (right - left > 1)
    {
        int div = GetReferenceValue(arr, left, right);
        Quick_Sort(arr, left, div);
        Quick_Sort(arr, div + 1, right);
    }
}

int main()
{
    int array[] = { 1,2,3,9,4,1,4,4,2 };
    //int array1[] = { 1,2,3,9,4,1,4,4,2 };
    int sz = sizeof(array) / sizeof(array[0]);
    Quick_Sort(array, 0, sz);
    Print(array, sz);
    system("pause");
    return 0;
}


void Print(int* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
}
void Heap_Adjust(int array[] , int parent , int size)
{
    int child = 2 * parent + 1;
    while (child < size)
    {
        if (child + 1 < size && array[child + 1] > array[child])
        {
            child += 1;
        }
        if (array[child] > array[parent])
        {
            swap(array[child], array[parent]);
            parent = child;
            child = 2 * parent+ 1;
        }
        else
            return; 
    }
}

void Head_Sort(int* arr, int size)
{
    int end = size - 1;
    for (int root = (size - 1) / 2; root >= 0; root--)
    {
        Heap_Adjust(arr, root,size);
    }
    while (end)
    {
        swap(arr[end], arr[0]);
        Heap_Adjust(arr,0,end);
        end--;
    }
}

int main()
{
    int array[] = { 1,2,3,9,4,1,4,4,2 };
    //int array1[] = { 1,2,3,9,4,1,4,4,2 };
    int sz = sizeof(array) / sizeof(array[0]);
    Head_Sort(array,sz);
    Print(array, sz);
    system("pause");
    return 0;
}


void Heap_Adjust(int* arr, int parent, int size)
{
    int child = 2 * parent + 1;
    while (child > size)
    {
        if (child + 1 < size && arr[child] < arr[child + 1])
        {
            child += 1;
        }
        if (arr[child] < arr[parent])
        {
            swap(arr[child], arr[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
            return;
    }
}

void Heap_Sort(int * arr, int size)
{
    int end = size - 1;

    for (int root = (size-1) / 2;root > 0;root--)
    {
        Heap_Adjust(arr,root,size);
    }
    while (end)
    {
        swap(arr[end], arr[0]);
        Heap_Adjust(arr,0,end);
        end--;
    }
}


int MaxValue(string s)
{
    if(s.size() == 0)
    {
        return 0;
    }
    else
    {
        int num = atoi(s.c_str());
        for (size_t i = 0; i < s.size(); ++i)
        {
            for (size_t j = i; j < s.size(); ++j)
            {
                if (s[i] == '0')
                {
                    s[i] = '1';
                }
                else if (s[i] == '1')
                {
                    s[i] = '0';
                }
                int temp = atoi(s.c_str());
            }
        }

    }
}


if (read(sock_fd, buf) > 0)
{
    dosomething();
}

class Base
{
public:
    void fun1()
    {
        fun2();
    }

    virtual void fun2()  // 虚函数
    {
        cout << "Base::fun2()" << endl;
    }
};

class Derived : public Base
{
public:
    virtual void fun2()  // 虚函数
    {
        cout << "Derived:fun2()" << endl;
    }
};

int main()
{
    Derived d;
    Base* pBase = &d;
    pBase->fun1();
    system("pause");
    return 0;
}

class CFather
{
public:
    CFather()
    {
        cout << "Constructor Father" << endl;
    }
    virtual void hello() // 虚函数
    {
        cout << "hello from father" << endl;
    }

    virtual void bye() // 虚函数
    {
        cout << "bye from father" << endl;
    }
    ~CFather()
    {
        cout << "Destructor Father" << endl;
    }
};

// 派生类
class CSon : public CFather
{
public:
    CSon() // 构造函数
    {
        hello();
    }

    ~CSon()  // 析构函数
    {
       // bye();
        cout << "CSON Destructor" << endl;
    }

    virtual void hello() // 虚函数
    {
        cout << "hello from son" << endl;
    }
};

int main()
{
    CSon son;  
    CFather* pfather;
    pfather = &son;
    pfather->hello(); //多态
    //system("pause");
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        unordered_map<char, int> M;
        string temp = to_string(num);
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            M[temp[i]]++;
        }
        string res;
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            auto it = M.find(temp[i]);
            if (it != M.end())
            {
                if (it->second == 1)
                {
                    res += temp[i];
                }
            }
        }
    }

    return 0;
}


#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        unordered_map<char, int> M;
        int min = 2147483647;
        for (size_t i = 0; i < str.size(); ++i)
        {
            M[str[i]]++;
        }
        for (auto it : M)
        {
            if (it.second < min)
            {
                min = it.second;
            }
        }
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (M[str[i]] == min)
            {
                str.erase(str.begin() + i);
                i--;
            }
        }
        cout << str << endl;
    }
    return 0;
}


#include<iostream>
#include<map>
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    multimap<int, int,greater<int>>mp;
    // multimap第三个参数默认为less<Key>,即 less<int>
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 4;
        b = rand() % 4;
        //插入
        mp.insert(pair<int, int>(a, b));
    }
    map<int, int>::iterator iter;
    //遍历输出
    for (iter = mp.begin(); iter != mp.end(); iter++)
        cout << iter->first << " " << iter->second << endl;
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }
    bool operator==(const Person& p) const
    {
        return name == p.name && age == p.age;
    }
};

size_t person_hash(const Person& p)
{
    return hash<string>()(p.name) ^ hash<int>()(p.age);
}



int main(int argc, char* argv[])
{
    //ERRO: unordered_map<Person,int,decltype(&person_hash)> ids;
    //ERRO: unordered_map<Person,int,person_hash> ids(100, person_hash );
    //OK: unordered_map<Person, int, decltype(&person_hash)> ids(100, person_hash );
    unordered_map<Person, int, function<size_t(const Person& p)>> ids(100, person_hash); //需要把person_hash传入构造函数
    ids[Person("Mark", 17)] = 40561;
    ids[Person("Andrew", 16)] = 40562;
    for (auto ii = ids.begin(); ii != ids.end(); ii++)
        cout << ii->first.name
        << " " << ii->first.age
        << " : " << ii->second
        << endl;
    return 0;
}

#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
    string s;
    map<char, int> mp;
    while (cin >> s) {
        //每次循环都要清一下map
        mp.clear();
        for (char c : s) {
            if (mp.find(c) == mp.end()) {
                mp.emplace(make_pair(c, 1));
            }
            else {
                ++mp[c];
            }
        }
        //用迭代器范围初始化一个vector
        vector<pair<char, int>> vec(mp.begin(), mp.end());
        //因为map已经依照键排序了，所以用稳定排序当次数一样时，会保持原来的先后关系，即ASCII码的升序
        stable_sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            //用Lambda来写配合算法使用的小函数是非常方便的
            return a.second > b.second;
        });
        for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
            cout << iter->first;
        }
        cout << endl;
    }
}
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;


class Cmp {
    bool operator()(const pair<char, int>& left, const pair<char, int>& right)
    {

        if (left.second == right.second)
        {
            return left.first > right.first;
        }
        else
        {
            return left.second > right.second;
        }
    }
};

string camelCase(string newString) {
    if (newString.size() == 0)
    {
        return newString;
    }
    string res;
    bool flag = 0;
    for (size_t i = 0; i < newString.size(); ++i)
    {

        if ((newString[i] >= 'A' && newString[i] <= 'Z') || (newString[i] >= 'a' && newString[i] <= 'z')
            || (newString[i] >= '0' && newString[i] <= '9'))
        {
            if (flag == 0 && (newString[i] >= 'A' && newString[i] <= 'Z')) // 小写
            {
                res.push_back(tolower(res[i]));
                flag = 1;
            }
            else
            {

            }
        }
    }
}
 //cin >> line;
    string ans;
    bool first = false;//代表是第一个字母已经写过了，之后的空格后的大写字母可以弄成大写了。
    if ((line[0] >= '0' && line[0] <= '9') || (line[0] >= 'a' && line[0] <= 'z'))
    {
        ans = line[0];
        first = true;
    }
    else if (line[0] >= 'A' && line[0] <= 'Z')
    {
        ans = line[0] + 32;
        first = true;
    }
    bool flag = false;
    for (int i = 1; i < line.size(); i++)
    {
        if ((line[i] >= '0' && line[i] <= '9'))//符合条件,[0-9,a-z]
        {
            ans = ans + line[i];
            flag = false;
        }
        else if (line[i] >= 'a' && line[i] <= 'z')
        {
            if (flag)
            {
                char x = line[i] - 32;
                ans = ans + x;
            }
            else
                ans = ans + line[i];
            flag = false;
        }
        else if (line[i] >= 'A' && line[i] <= 'Z')//符合条件:[A-Z]
        {
            if (flag && !first)
            {
                char x = line[i] + 32;
                ans = ans + x;
                first = true;
            }
            else if (flag && first) {
                ans = ans + line[i];
            }
            else
            {
                char x = line[i] + 32;
                ans = ans + x;
            }
            flag = false;
        }
        else//不符合条件的字符
        {
            flag = true;
        }
    }
    cout << ans << endl;

#include <iostream>
#include <string>
using namespace std;

string camelCase(string newString)
{
    string ans;
    bool first = false;
    if ((newString[0] >= '0' && newString[0] <= '9') || (newString[0] >= 'a' && newString[0] <= 'z'))
    {
        ans = newString[0];
        first = true;
    }
    else if (newString[0] >= 'A' && newString[0] <= 'Z')
    {
        ans = newString[0] + 32;
        first = true;
    }
    bool flag = false;
    for (int i = 1; i < newString.size(); i++)
    {
        if ((newString[i] >= '0' && newString[i] <= '9'))//符合条件,[0-9,a-z]
        {
            ans = ans + newString[i];
            flag = false;
        }
        else if (newString[i] >= 'a' && newString[i] <= 'z')
        {
            if (flag)
            {
                char x = newString[i] - 32;
                ans = ans + x;
            }
            else
                ans = ans + newString[i];
            flag = false;
        }
        else if (newString[i] >= 'A' && newString[i] <= 'Z')//符合条件:[A-Z]
        {
            if (flag && !first)
            {
                char x = newString[i] + 32;
                ans = ans + x;
                first = true;
            }
            else if (flag && first) {
                ans = ans + newString[i];
            }
            else
            {
                char x = newString[i] + 32;
                ans = ans + x;
            }
            flag = false;
        }
        else//不符合条件的字符
        {
            flag = true;
        }
    }
    return ans;
}

class Base
{
public:
    void fun1()
    {
        fun2();
    }

    virtual void fun2()  // 虚函数
    {
        cout << "Base::fun2()" << endl;
    }
};

class Derived : public Base
{
public:
    virtual void fun2()  // 虚函数
    {
        cout << "Derived:fun2()" << endl;
    }
};

int main()
{
    Base* p = new Derived();
    p->fun2();
    p->Base::fun2();
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
        int count = 0;
    while (count < T)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> vec(m, vector<int>(2, 0)); //m行 记录 u,v
        unordered_map<int, int> M;
        for (size_t i = 0; i < m; ++i)
        {
            cin >> vec[i][0] >> vec[i][1];
            M[vec[i][0]]++;
            M[vec[i][1]]++;
        }
        vector<int> vec1(k, 0); //表示旅行记录中的记录
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            cin >> vec1[i];
        }
        bool flag = 0;
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            if (M.find(vec1[i]) == M.end())
            {
                cout << "NO" << endl;
                break;
            }
        }
        cout << "YES" << endl;
        count++;
    }
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 32 22";
        int count = 0;
        int num1, num2;
        cin >> num1 >> num2;
        if (str.size() > 1)
        {
            bool begin = 1;
            int end = str.find(' ');
            if (end == -1)
            {
                cout << str.substr(1, str.size() - 1) << endl;
            }
            else
            {
                int count = 0;
                for (int i = 1; i < str.size(); ++i)
                {
                    if (count >= 20 && count % 20 == 0)
                    {
                        cout << endl;
                        count = 0;
                    }
                    else {
                        if (str[i] == ' '&& begin == false)
                        {
                            cout << ';';
                        }
                        else
                        {
                            if (str[i] != ' ')
                            {
                                cout << str[i];
                                count++;
                                begin = false;
                            }
                        }
                    }
                }
            }
        }
    return 0;
}*/