#include <bits/stdc++.h>
using namespace std;
const int Maxn=100010;
char Skill[10][7][4]=
{ 
    {"","QQQ","QQQ","QQQ","QQQ","QQQ","QQQ"},
    {"","QQW","QWQ","WQQ","WQQ","WQQ","WQQ"},
    {"","QQE","QEQ","EQQ","EQQ","EQQ","EQQ"},
    {"","WWW","WWW","WWW","WWW","WWW","WWW"},
    {"","QWW","WQW","WWQ","WWQ","WWQ","WWQ"},
    {"","WWE","WEW","EWW","EWW","EWW","EWW"},
    {"","EEE","EEE","EEE","EEE","EEE","EEE"},
    {"","QEE","EQE","EEQ","EEQ","EEQ","EEQ"},
    {"","WEE","EWE","EEW","EEW","EEW","EEW"},
    {"","QWE","QEW","EQW","EWQ","WEQ","WQE"},
};
map<char,int> Map;
char ch[Maxn];
int p[Maxn];
int A[Maxn][7];
inline int check(int a,int b,int x,int y)
{
	if(Skill[a][x][0]==Skill[b][y][0]&&Skill[a][x][1]==Skill[b][y][1]&&Skill[a][x][2]==Skill[b][y][2]) return 0;
	else if(Skill[a][x][1]==Skill[b][y][0]&&Skill[a][x][2]==Skill[b][y][1])	return 1;
	else if(Skill[a][x][2]==Skill[b][y][0]) return 2;
	else return 3;
}
void Solve()
{
    Map['X']=0;Map['V']=1;Map['G']=2;
	Map['C']=3;Map['X']=4;Map['Z']=5;
	Map['T']=6;Map['F']=7;Map['D']=8;Map['B']=9;
	int ans=0;
	while(scanf("%s",ch+1)!=EOF)
    {
		int len=strlen(ch+1);
		ans=0;
		for(int i=1;i<=len;i++) p[i]=Map[ch[i]];
		ans+=len; 
		memset(A,0x3f,sizeof(A));
		A[1][1]=3;A[1][2]=3;A[1][3]=3;A[1][4]=3;A[1][5]=3;A[1][6]=3;
		for(int i=2;i<=len;i++)
			for(int j=1;j<=6;j++)
				for(int k=1;k<=6;k++)
					A[i][j]=min(A[i][j],A[i-1][k]+check(p[i-1],p[i],k,j));
		int mi=A[len][1];
		for(int i=1;i<=6;i++) mi=min(mi,A[len][i]);
		printf("%d\n",ans+mi);
	}
}
int main()
{	
    Solve();
    system("pause");
    return 0;
}
