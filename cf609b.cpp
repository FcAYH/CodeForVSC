#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=6000;
const int Inf=0x3f3f3f3f;
int n,m;
int A[Maxn],B[Maxn];
int ans=Inf;
inline int cmp(int a,int b){return a<b;}
void Solve()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++) scanf("%d",&A[i]);
   for(int i=1;i<=n;i++) scanf("%d",&B[i]);
   sort(A+1,A+1+n,cmp);
   sort(B+1,B+1+n,cmp);
   for(int i=n+1;i<=2*n;i++) A[i]=A[i-n];
   for(int i=1;i<=n;i++)
   for(int i=1;i<=n;i++)
   {
       int Add=0,flag=0;
       if(B[1]>=A[i]) Add=B[1]-A[i];
       else Add=m-A[i]+B[1];
       //printf("<%d %d>\n",i,Add);

       for(int j=i+1;j<=n+i-1;j++) 
       {
           if((A[j]+Add)%m!=B[j-i+1]){flag=1; break ;}
       }
       if(!flag) ans=min(ans,Add);
   } 
   printf("%d\n",ans);
}
int main()
{
    Solve();
    system("pause");
    return 0;
}