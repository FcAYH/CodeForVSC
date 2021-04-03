#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
class CLIENT
{
    public:
        CLIENT(int t);
        CLIENT(CLIENT &p);
        ~CLIENT(){};
        void ChangeServerName(const char ch[]);
        void print();
    private:
        static char ServerName[200];
        static int ClientNum;
        int a;
};