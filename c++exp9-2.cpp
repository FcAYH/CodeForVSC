#include <bits/stdc++.h>
using namespace std;
template <class T>
class node
{ //结点类
public:
    T data;
    node *next;
};
template <class T>
class test
{
private:
    node<T> *head;   //头部
    node<T> *end;    //尾部
    int num;         //个数
    node<T> *now;    //当前
    node<T> *before; //之前
public:
    test(int a = 0); //构造函数
    ~test();
    void addp1();                        //在头部生成节点   ok
    void addp2();                        //在尾部生成节点    ok
    void addp3(int i);                   //在i处生成节点  ok
    void createp(int i, node<T> *inset); //在i处插入节点,需要一个node对象或指针作为参数  ok
    void deletep(int i);                 //删除节点          ok
    node<T> *getaddp(int i);             //传出地址用于访问和修改节点    ok
    void testall();                      //遍历链表
    node<T> *getinter();                 //获取链表头用于赋值等等。。。ok
    void showstate();                    //状态查看
    int getnum();                        //获取当前容量
    void operator=(test<T> &t);          //重载运算符=
    void insetlink(int i, test<T> &t);   //在当前链表的i处插入一个类链表
};
template <class T>
void test<T>::operator=(test<T> &t)
{
    if (this->getnum() != t.getnum())
    {
        cout << "error!" << endl;
    }
    else
    {
        int j = t.getnum();
        for (int n = 1; n <= j; n++)
        {
            (this->getaddp(n))->data = (t.getaddp(n))->data;
        }
    }
}

template <class T>
test<T>::test(int a)
{
    num = a;
    head = new node<T>;
    end = head;
    for (int i = 1; i <= a; i++)
    {
        node<T> *s = new node<T>;
        end->next = s;
        end = s;
    }
}
template <class T>
int test<T>::getnum()
{
    return num;
}

template <class T>
test<T>::~test()
{
    delete[] head;
}

template <class T>
void test<T>::addp1()
{
    num = num + 1;
    node<T> *s = new node<T>;
    s->data = rand() % 10;
    s->next = head;
    head = s;
}

template <class T>
void test<T>::addp2()
{
    num = num + 1;
    node<T> *s = new node<T>;
    end->data = 10;
    end->next = s;
    end = s;
    s->next = NULL;
}
template <class T>
void test<T>::addp3(int i)
{
    if (i >= 1 && i <= num)
    {
        node<T> *t = head;
        for (int j = 1; j <= i - 1; j++)
        {
            t = t->next;
        }
        node<T> *behind = t->next;
        node<T> *add = new node<T>;
        t->next = add;
        add->next = behind;
        num = num + 1;
    }
    else
    {
        cout << "error:  out of rage" << endl;
    }
}
template <class T>
node<T> *test<T>::getinter()
{
    return head;
}
template <class T>
void test<T>::showstate()
{
    cout << "recent data:" << endl;
    cout << "the length       :" << num << endl;
    cout << "the begin address:" << (int)head << endl;
    cout << "the end address  :" << (int)end << endl;
}
template <class T>
void test<T>::createp(int i, node<T> *inset)
{
    if (i >= 1 && i <= num)
    {
        node<T> *t = head;
        for (int j = 1; j <= i - 1; j++)
        {
            t = t->next;
        }
        node<T> *behind = t->next;
        node<T> *add = inset;
        t->next = add;
        add->next = behind;
        num = num + 1;
    }
    else
    {
        cout << "error:  out of rage" << endl;
    }
}
template <class T>
void test<T>::deletep(int i)
{
    if (i >= 1 && i <= num)
    {
        if (i == 1)
        {
            node<T> *deletedone = head;
            head = head->next;
            delete[] deletedone;
            num = num - 1;
        }
        else
        {
            node<T> *p = head;
            for (int j = 1; j <= i - 2; j++)
            {
                p = p->next;
            }
            node<T> *deletedone = p->next;
            p->next = (p->next)->next;
            delete[] deletedone;
        }
        num = num - 1;
    }
    else
    {

        cout << "node do not exist" << endl;
    }
}

template <class T>
node<T> *test<T>::getaddp(int i)
{
    if (i >= 1 && i <= num)
    {
        node<T> *t = head;
        for (int j = 1; j <= i - 1; j++)
        {
            t = t->next;
        }
        return t;
    }
    else
    {
        cout << "error:node do not exist" << endl;
        return head;
    }
}

/*-----------------辅助函数-------------*/
template <class T>
void copylinklist(test<T> &x, test<T> &y)
{ //复制  把后者的数据复制给前者（若不同长度则尾部数据有遗失）
    int i = x.getnum();
    int j = y.getnum();
    for (int m = 1, n = 1; m <= i && n <= j; m++, n++)
    {
        (x.getaddp(m))->data = (y.getaddp(n))->data;
    }
}

template <class T>
void test<T>::insetlink(int i, test<T> &t)
{
    this->num = this->num + t.num; //扩充链表大小
    int begin = i;
    int end = t.getnum();
    for (int j = 1; j <= end; j++)
    {
        node<T> *u = new node<T>;
        u->data = t.getaddp(j)->data;
        this->createp(begin, u);
        begin = begin + 1;
    }
}

int main()
{
    srand(time(0));

    test<int> my(5);
    {
        node<int> *n = my.getinter();
        for (int i = 1; i <= 5; i++)
        {
            n->data = i;
            n = n->next;
        }
    }

    cout << endl;
    {
        node<int> *pp = my.getinter();
        for (int j = 1; j <= 5; j++)
        {
            cout << pp->data << endl;
            pp = pp->next;
        }
    }

    cout << "create link succeed!" << endl;

    {
        my.addp1(); //头部增一测试
        node<int> *pp = my.getinter();
        for (int j = 1; j <= 6; j++)
        {
            cout << pp->data << endl;
            pp = pp->next;
        }
    }
    cout << "head add test succeed!" << endl;

    {
        my.addp2(); //尾部增一测试
        node<int> *pp = my.getinter();
        for (int j = 1; j <= 8; j++)
        {
            cout << pp->data << endl;
            pp = pp->next;
        }
    }
    cout << "end add test succeed!" << endl;

    {
        my.addp3(3); //任意位置增一测试
        node<int> *pp = my.getinter();
        for (int j = 1; j <= 8; j++)
        {
            cout << pp->data << endl;
            pp = pp->next;
        }
    }
    cout << "random add test succeed!" << endl;

    { //删除节点测试
        my.deletep(1);
        my.deletep(3);
        my.deletep(6);
        node<int> *pp = my.getinter();
        for (int j = 1; j <= 5; j++)
        {
            cout << pp->data << endl;
            pp = pp->next;
        }
        cout << "delete test succeed!" << endl;
    }

    cout << "following is another subject   A" << endl;
    test<int> A(5);
    A = my;
    {
        node<int> *pp = A.getinter();
        for (int j = 1; j <= 5; j++)
        {
            cout << pp->data << endl;
            pp = pp->next;
        }
        cout << "operator ''=''  function test succeed!" << endl;
    }

    cout << "expand my with the function insetlink()" << endl; //链表间的插入测试
    my.insetlink(3, A);
    {
        node<int> *pp = my.getinter();
        for (int j = 1; j <= 10; j++)
        {
            cout << pp->data << endl;
            pp = pp->next;
        }
        cout << "succeed!" << endl;
    }

    cout << endl;
    my.insetlink(10, A); //按题目要求 加入尾部的测试
    {
        node<int> *pp = my.getinter();
        for (int j = 1; j <= 15; j++)
        {
            cout << pp->data << endl;
            pp = pp->next;
        }
    }
    return 0;
}
