
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int t=200;
    while(1)
    {
        system("D:\\MyDocuments\\MYCODE\\CodeForVSCfc\\Datamaker.exe > D:\\MyDocuments\\MYCODE\\CodeForVSCfc\\data.in");
        system("D:\\MyDocuments\\MYCODE\\CodeForVSCfc\\niuke9e.exe < D:\\MyDocuments\\MYCODE\\CodeForVSCfc\\data.in > D:\\MyDocuments\\MYCODE\\CodeForVSCfc\\My.out"); //printf("ss");
        system("D:\\MyDocuments\\MYCODE\\CodeForVSCfc\\mul9E.exe < D:\\MyDocuments\\MYCODE\\CodeForVSCfc\\data.in > D:\\MyDocuments\\MYCODE\\CodeForVSCfc\\Zyc.out"); //printf("dd");
        if(system("D:\\MyDocuments\\MYCODE\\CodeForVSCfc\\My.out D:\\MyDocuments\\MYCODE\\CodeForVSC\\Zyc.out"))   break;
        //printf("xx");
    }
    
    cout<<"error"<<endl;
    system("pause");
    return 0;
}
