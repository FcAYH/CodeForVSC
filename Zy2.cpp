#include <iostream>
#include <cstring>
using namespace std;
class MyString
{
private:
    char s[100];

public:
    MyString(const char *p = NULL)
    {
        if (p == NULL)
            s[0] = '\0';
        else
        {
            strncpy(s, p, 99);
        }
    }
    MyString(int i)
    {
        int j;
        for (j = 0; j < i && j < 99; j++)
            s[j] = ' ';
        s[j] = '\0';
    }
    void display()
    {
        printf("<%s>\n", s);
    }
    MyString &operator=(const MyString &str)
    {
        strncpy(s, str.s, 99);
        return *this;
    }
    MyString &operator[](int i)
    {
        static MyString str;
        int j;
        str = *this;
        for (j = i; s[j] != '\0'; j++)
            str.s[j - i] = str.s[j];
        str.s[j - i] = '\0';
        return str;
    }
    MyString &operator++(int i)
    {
        static MyString str;
        str = *this;
        *this = (s[0] == '\0') ? *this : (*this)[1];
        return str;
    }
};
int main()
{
    MyString s1 = "0123456789", s2(5), s3;
    s1.display();
    s2.display();
    s3.display();
    s3 = s1;
    s3.display();
    s2 = s1[2];
    s2.display();
    s1.display();
    s3 = s2++;
    s2.display();
    s3.display();
}
