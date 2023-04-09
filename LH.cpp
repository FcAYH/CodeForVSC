#include <bits/stdc++.h>

using namespace std;

struct Student
{
    string name;
    int age;
    int marks;
};

// 按照年龄从小到大排序，如果年龄相同，按照分数从大到小排序，如果分数也相同，按照名字的字典序从小到大排序
bool Student_compare(Student a, Student b)
{
    if (a.age != b.age)
        return a.age < b.age;
    else if (a.marks != b.marks)
        return a.marks > b.marks;
    else
        return a.name < b.name;
}

bool int_compare(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    Student s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].age >> s[i].marks;
    }

    sort(s, s + n, Student_compare);

    for (int i = 0; i < n; i++)
    {
        cout << s[i].name << " " << s[i].age << " " << s[i].marks << endl;
    }

    int nums[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> nums[i];
    }

    // nums 从大到小排序
    sort(nums, nums + 10, int_compare);

    return 0;
}
