#include<bits/stdc++.h>
using namespace std;
const int Maxn=100010;
int First,N;
int Address[Maxn];
int Val[Maxn];
struct ANS{int add,val,next;}Ans[Maxn];
void Solve()
{
    scanf("%d%d",&First,&N);
    for(int i=1;i<=N;i++)
    {
        int loc,val,Next;
        scanf("%d%d%d",&loc,&val,&Next);
        Address[loc]=Next,Val[loc]=val;
    }
    int cnt=0;
    for(int i=First;~i;i=Address[i]) 
    {
        Ans[++cnt].val=Val[i],Ans[cnt].next=Address[i],Ans[cnt].add=i;
    }
    for(int i=1;i<=cnt/2;i++)
    {
        if(i!=cnt/2)
        {
            printf("%05d %d %05d\n",Ans[cnt-i+1].add,Ans[cnt-i+1].val,Ans[i].add);
            printf("%05d %d %05d\n",Ans[i].add,Ans[i].val,Ans[cnt-i].add);
        }
        else if(i==cnt/2&&!(cnt%2))
        {
            printf("%05d %d %05d\n",Ans[cnt-i+1].add,Ans[cnt-i+1].val,Ans[i].add);
            printf("%05d %d %d\n",Ans[i].add,Ans[i].val,-1);
        }
        else
        {
            printf("%05d %d %05d\n",Ans[cnt-i+1].add,Ans[cnt-i+1].val,Ans[i].add);
            printf("%05d %d %05d\n",Ans[i].add,Ans[i].val,Ans[cnt-i].add);
        }
        
    }  
    if(cnt%2) printf("%05d %d %d\n",Ans[cnt/2+1].add,Ans[cnt/2+1].val,-1);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
00100 7
00000 4 99999
00100 1 12309
68237 6 12432
33218 3 00000
99999 5 68237
12309 2 33218
12432 9 -1

00000 2
00000 1 11111
11111 2 -1
*/