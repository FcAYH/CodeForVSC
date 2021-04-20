#include <iostream>
#include <cstring>
using namespace std;
class Person
{
private:
    int id;
    char *name;

public:
    Person(int Id, char *Name) : id(Id)
    {
        if (Name != NULL)
        {
            this->name = new char[strlen(Name) + 1];
            strcpy(this->name, Name);
        }
        else
        {
            this->name = new char[5];
            strcpy(this->name, "无名氏");
        }
    }
    ~Person() { delete[] name; }

public:
    void showData()
    {
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
    }
};
class Teacher : public Person
{
private:
    int degree;
    int dep;

public:
    Teacher(int Id, char *Name, int Degree, int Dep)
        : Person(Id, Name),
          degree(Degree),
          dep(Dep)
    {
    }
    ~Teacher()
    {
    }

public:
    void showDataT()
    {
        cout << "Degree: " << degree << endl;
        cout << "Dep: " << dep << endl;
    }
};
class Student : public Person
{
private:
    int old;
    int sno;

public:
    Student(int Id, char *Name, int Old, int Sno)
        : Person(Id, Name),
          old(Old),
          sno(Sno)
    {
    }
    ~Student() {}

public:
    void showDataS()
    {
        cout << "Old: " << old << endl;
        cout << "Sno: " << sno << endl;
    }
};
class Stud
{
private:
    char *addr;
    int tel;

public:
    Stud(char *Addr, int Tele) : tel(Tele)
    {
        if (Addr != NULL)
        {
            this->addr = new char[strlen(Addr) + 1];
            strcpy(this->addr, Addr);
        }
        else
        {
            this->addr = new char[7];
            strcpy(this->addr, "未填写地址");
        }
    }
    ~Stud() { delete[] addr; }

public:
    void showDataInfo()
    {
        cout << "Address: " << addr << endl;
        cout << "Telephone: " << tel << endl;
    }
};
class Score : public Student, public Stud
{
private:
    int math;
    int eng;

public:
    Score(int Id, char *Name, int Old, int Sno, int Math, int Eng, char *Addr, int Tele)
        : Student(Id, Name, Old, Sno),
          Stud(Addr, Tele),
          math(Math),
          eng(Eng)
    {
    }
    ~Score() {}

public:
    void showDataScore()
    {
        cout << "Math: " << math << endl;
        cout << "English: " << eng << endl;
    }
};
int main()
{
    Score c1(3035, "张三", 19, 2, 90, 78, NULL, 10086);

    // c1.showData();
    // c1.showDataS();
    // c1.showDataInfo();
    // c1.showDataScore();
    Teacher t1(1010, "李老师", 2, 3);

    t1.showData();
    t1.showDataT();
    puts("df");
    return 0;
}
