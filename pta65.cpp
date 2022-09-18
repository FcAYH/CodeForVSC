#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int L,N;
char Beg[10];
inline void Solve()
{
    int Now=L;
    while(Beg[Now]=='a') Now--;
    Beg[Now]--;
    for(int i=Now+1;i<=L;i++) Beg[i]='z';
}
int main()
{
    scanf("%d%d",&L,&N);
    for(int i=1;i<=L;i++) Beg[i]='z';
    for(int i=2;i<=N;i++) Solve();
    printf("%s",Beg+1);
    system("pause");
    return 0;
}