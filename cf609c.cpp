#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=3000000;
int n,k;
char s[Maxn];
char A[Maxn];

/*
void Work_even()
{
    int pt=n/2,Tag=0;
    for(int i=pt;i>=1;i--)
    {
        if(A[i]>=A[i+pt]) B[i]=A[i],B[i+pt]=A[i];
        else
        {
            B[i]=A[i]+1,B[i+pt]=A[i]+1;
            Tag=i; break ;
        }
    }
    for(int i=1;i<Tag;i++) B[i]=A[i],B[i+pt]=A[i];
    printf("%d\n",n);
    for(int i=1;i<=n;i++) printf("%d",B[i]);
}
void Work_odd()
{
    int pt=n/2,flag=1;
    for(int i=1;i<=pt;i++) C[i]=A[i];
    C[pt+1]=A[pt+1]+1;
    for(int i=pt+1+1;i<=n;i++) C[i]=A[i-pt-1];
    B[pt+1]=A[pt+1];
    for(int i=pt;i>=1;i--)
    {
        if(A[i]>=A[i+pt+1]) B[i]=A[i],B[i+pt+1]=A[i];
        else{flag=0; break ;}
    }
    printf("%d\n",n);
    if(flag) for(int i=1;i<=n;i++) printf("%d",B[i]);
    else for(int i=1;i<=n;i++) printf("%d",C[i]);
}
*/
void Solve()
{
    scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=k;i++) A[i]=s[i];
	for(int i=k+1;i<=n;i++) A[i]=A[i-k];
	if(strcmp(s+1,A+1)>0)
	{
		int p=k;
		if(A[p]<='8') A[p]++;
		else if(A[p] == '9')
		{
			A[p] = '0';
			for(int i=p-1;i>=1;i--) 
            {
                if(A[i]<='8'){A[i]++; break ;}
				else A[i] = '0';
            }
		}
		for(int i=k+1;i<=n;i++) A[i]=A[i-k];
	}
	cout<<strlen(A+1)<<endl<<(A+1)<<endl;
    /*if(!(n%2)) Work_even();
    else Work_odd();*/
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
20 4
1245454432421234134
*/

