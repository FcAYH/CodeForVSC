//作业 ：编写一个学生类
//随机生成n个学生  (n>=100 n<=1000000)
//并保存到向量容器里 然后调用stl sort  对学生进行排序 基于学号 姓名
// 降序 然后输出排序后的学生 （每行四个学生 统计n不同时 排序所需要的时间
// n=1000,10000,100000,1000000

#include <bits\stdc++.h>
#include <windows.h>

using namespace std;

class Student
{
private:
    int nId;
    char *sName;

public:
    Student(int id, char *name) : nId(id)
    {
        int length = strlen(name);
        sName = new char[length + 1];

        strcpy(this->sName, name);
    };
    ~Student()
    {
        if (sName != nullptr)
            delete[] sName;
    }
    Student(const Student &t)
    {
        int length = strlen(t.sName);

        this->nId = t.nId;
        this->sName = new char[length + 1];

        strcpy(this->sName, t.sName);
    }
    Student operator=(const Student &t)
    {
        int length = strlen(t.sName);

        this->nId = t.nId;
        this->sName = new char[length + 1];

        strcpy(this->sName, t.sName);

        return *this;
    }
    bool operator>(const Student &t)
    {
        int temp = strcmp(this->sName, t.sName);
        return (temp == 0) ? this->nId > t.nId : (temp > 0);
    }
    bool operator<(const Student &t)
    {
        int temp = strcmp(this->sName, t.sName);
        return (temp == 0) ? this->nId < t.nId : (temp < 0);
    }

public:
    int GetNid() { return this->nId; }
    char *GetName() { return this->sName; }
};

template <class T>
void MySort(vector<T> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] < v[j])
            {
                T t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }
    }
}

template <class T>
void ShowData(vector<T> &v)
{
    cout << endl;

    typename vector<T>::iterator it;
    int nNum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        nNum++;

        if (nNum > 100)
            break;

        cout << setw(8) << v[i].GetNid();

        if (nNum % 10 == 0)
            cout << endl;
    }
}

bool cmp(Student a, Student b)
{
    return a > b;
}

char *randstr(const int len)
{
    char *str = new char[len + 1];
    int i;
    for (i = 0; i < len - 1; ++i)
    {
        switch ((rand() % 3))
        {
        case 1:
            str[i] = 'A' + rand() % 26;
            break;
        case 2:
            str[i] = 'a' + rand() % 26;
            break;
        default:
            str[i] = '0' + rand() % 10;
            break;
        }
    }
    str[++i] = '\0';
    return str;
}

int main()
{
    vector<Student> v1, v2; //模板类
    int nNum = 1000;
    int N;
    unsigned t1, t2;

    srand(GetTickCount()); //设置 随机种子 时钟滴答数
    for (int i = 0; i < nNum; i++)
    {
        N = (rand() * rand()) % 1000000; //产生百万以内的随机数
        Student *student = new Student(N, randstr(7));
        v1.push_back(*student);
        v2.push_back(*student); //rand 65000
        delete student;
    }
    // showData(v1);

    t1 = GetTickCount();
    MySort(v1);
    t2 = GetTickCount();

    cout << "\nMySort排序用时" << t2 - t1 << "ms" << endl;
    ShowData(v1);
    //下面是使用算法库的排序
    t1 = GetTickCount();
    sort(v2.begin(), v2.end(), cmp); //注意其中使用了函数对象
    t2 = GetTickCount();
    cout << "\nsort排序用时" << t2 - t1 << "ms" << endl;
    ShowData(v2);
    system("pause");
    return 0;
}
