#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=10;
int t;
int A[10];
char s[200];
char Pri[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
inline int Change_Ten(int l,int r)
{
    int jc=1,ret=0;
    for(int i=r;i>=l;i--) 
    {
        if(s[i]=='1') ret+=jc; jc<<=1;
    }
    return ret;
}
inline int Change_Sixteen(int x,int flag)
{
    char Print[10]={'0','0','0','0','0','0','0','0','0','0'};
    int l=1;
    while(x)
    {
        Print[l]=Pri[x%16];
        x/=16; l++;
    }
    for(int i=l-1;i>=1;i--) printf("%c",Print[i]); 
    if(l==1) printf("0");
    if(flag) printf(":"); 
}
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>(s+1);
        for(int i=1;i<=8;i++) A[i]=Change_Ten((i-1)*16+1,(i-1)*16+16);
        int left=0,right=0,maxl=0;
        for(int i=8;i>=1;i--)
        {
            if(!A[i])
            {
                int j=i,cnt=0;
                while(j>=1) 
                {
                    if(!A[j]) cnt++,j--;
                    else break ;
                }
                if(cnt>maxl) left=j+1,right=i,maxl=cnt; 
            }
        }
        for(int i=1;i<left-1;i++) Change_Sixteen(A[i],1);
        if(left-1>0) Change_Sixteen(A[left-1],0);
        printf("::");
        for(int i=right+1;i<8;i++) Change_Sixteen(A[i],1);
        if(right+1<9) Change_Sixteen(A[8],0); 
        puts("");
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*

3
00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000010010001101000101011001111000100110101011000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000010010001100000000000000000000000000000000000000000000000001000101011001111000100110101011
*/