/*
#include<stdio.h>
using namespace std;
int main()
{
    printf("Input num: ");
    int a,sum;
    sum=0;
    do
    {
        scanf("%d",&a);
        sum=a+sum;
        printf("sum = %d\n",sum);
        if(a>0) printf("Input num: ");
    } while (a>0);
    return 0;
}
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Maxn=500;
int n;
struct STU{int sco;char name[30];}stu[Maxn];
int cmp(STU a,STU b){return a.sco>b.sco;}
void Solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>stu[i].name>>stu[i].sco;
    sort(stu+1,stu+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        cout<<stu[i].name<<" "<<stu[i].sco;
        if(stu[i].sco==0) cout<<" "<<"Bad"<<endl;
        else if(stu[i].sco>=1&&stu[i].sco<200) cout<<" "<<"Not good"<<endl;
        else if(stu[i].sco>=200&&stu[i].sco<300) cout<<" "<<"Bronze medal"<<endl;
        else if(stu[i].sco>=300&&stu[i].sco<400) cout<<" "<<"Silver medal"<<endl;
        else if(stu[i].sco>=400) cout<<" "<<"Gold medal"<<endl; 
    }
}
int main()
{
    Solve();
    //system("pause");
    return 0;
}
