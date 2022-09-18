#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100001;
int N,C;
struct Student{int id,sco;string name;}stu[Maxn];
inline int cmp1(Student a,Student b){return a.id<b.id;}
inline int cmp2(Student a,Student b){return (a.name==b.name)?a.id<b.id:a.name<b.name;}
inline int cmp3(Student a,Student b){return (a.sco==b.sco)?a.id<b.id:a.sco<b.sco;}
void Solve()
{
    ios::sync_with_stdio(false);
    cin>>N>>C;
    for(int i=1;i<=N;i++) cin>>stu[i].id>>stu[i].name>>stu[i].sco;
    switch (C)
    {
        case 1:
        {
            sort(stu+1,stu+1+N,cmp1);
            for(int i=1;i<=N;i++) 
            {
                cout.fill('0');//设置填充字符
                cout.width(6);
                cout<<stu[i].id<<" ";
                
                cout<<stu[i].name<<" "<<stu[i].sco<<endl;
            }
            break;
        }
        case 2:
        {
            sort(stu+1,stu+1+N,cmp2);
            for(int i=1;i<=N;i++)  
            {
                cout.fill('0');//设置填充字符
                cout.width(6);
                cout<<stu[i].id<<" ";
                
                cout<<stu[i].name<<" "<<stu[i].sco<<endl;
            }
            break;
        }
        case 3:
        {
            sort(stu+1,stu+1+N,cmp3);
            for(int i=1;i<=N;i++)  
            {
                cout.fill('0');//设置填充字符
                cout.width(6);
                cout<<stu[i].id<<" ";
                
                cout<<stu[i].name<<" "<<stu[i].sco<<endl;
            }
            break ;
        }
        default:
            break;
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}