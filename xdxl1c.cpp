#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=10;
int LAB[Maxn];
int BUT[Maxn];
inline int read()
{
    int fl=1,rt=0; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fl=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){rt=rt*10+ch-'0'; ch=getchar();}
    return fl*rt;
}
void Solve()
{
    int t;
    t=read();
    while(t--)
    {
        for(int i=1;i<=5;i++)
        {
            int D,b[10];
            D=read(),b[1]=read(),b[2]=read(),b[3]=read(),b[4]=read();
            if(i==1)
            {
                if(D==1) 
                {
                    printf("%d %d\n",2,b[2]),BUT[1]=2,LAB[1]=b[2];
                }
                if(D==2)
                {
                    printf("%d %d\n",2,b[2]),BUT[1]=2,LAB[1]=b[2];
                }
                if(D==3)
                {
                    printf("%d %d\n",3,b[3]),BUT[1]=3,LAB[1]=b[3];
                }
                if(D==4)
                {
                    printf("%d %d\n",4,b[4]),BUT[1]=4,LAB[1]=b[4];
                }
            }
            if(i==2)
            {
                if(D==1)
                {
                    int B=1;
                    for(B=1;B<=4;B++) if(b[B]==4) break ;  
                    printf("%d %d\n",B,4),BUT[2]=B,LAB[2]=4;
                }
                if(D==2)
                {
                    printf("%d %d\n",BUT[1],b[BUT[1]]),BUT[2]=BUT[1],LAB[2]=b[BUT[1]];
                }
                if(D==3)
                {
                    printf("%d %d\n",1,b[1]),BUT[2]=1,LAB[2]=b[1];
                }
                if(D==4)
                {
                    printf("%d %d\n",BUT[1],b[BUT[1]]),BUT[2]=BUT[1],LAB[2]=b[BUT[1]];
                }   
            }
            if(i==3)
            {
                if(D==1) 
                {
                    int B=1;
                    for(B=1;B<=4;B++) if(b[B]==LAB[2]) break ;  
                    printf("%d %d\n",B,LAB[2]),BUT[3]=B,LAB[3]=LAB[2];
                }
                if(D==2) 
                {
                    int B=1;
                    for(B=1;B<=4;B++) if(b[B]==LAB[1]) break ; 
                    printf("%d %d\n",B,LAB[1]),BUT[3]=B,LAB[3]=LAB[1];
                }
                if(D==3) 
                {
                    printf("%d %d\n",3,b[3]),BUT[3]=3,LAB[3]=b[3];
                }
                if(D==4) 
                {
                    int B=1;
                    for(B=1;B<=4;B++) if(b[B]==4) break ;  
                    printf("%d %d\n",B,4),BUT[3]=B,LAB[3]=4;
                }    
            }
            if(i==4)
            {
                if(D==1) 
                {
                    printf("%d %d\n",BUT[1],b[BUT[1]]),BUT[4]=BUT[1],LAB[4]=b[BUT[1]];
                }
                if(D==2) 
                {
                    printf("%d %d\n",1,b[1]),BUT[4]=1,LAB[4]=b[1];
                }
                if(D==3) 
                {
                    printf("%d %d\n",BUT[2],b[BUT[2]]),BUT[4]=BUT[2],LAB[4]=b[BUT[2]];
                }
                if(D==4) 
                {
                    printf("%d %d\n",BUT[2],b[BUT[2]]),BUT[4]=BUT[2],LAB[4]=b[BUT[2]];
                }
            }
            if(i==5)
            {
                if(D==1) 
                {
                    int B=1;
                    for(B=1;B<=4;B++) if(b[B]==LAB[1]) break ;
                    printf("%d %d\n",B,LAB[1]);
                }
                if(D==2) 
                {
                    int B=1;
                    for(B=1;B<=4;B++) if(b[B]==LAB[2]) break ;
                    printf("%d %d\n",B,LAB[2]);
                }
                if(D==3) 
                {
                    int B=1;
                    for(B=1;B<=4;B++) if(b[B]==LAB[4]) break ;
                    printf("%d %d\n",B,LAB[4]);
                }
                if(D==4) 
                {
                    int B=1;
                    for(B=1;B<=4;B++) if(b[B]==LAB[3]) break ;
                    printf("%d %d\n",B,LAB[3]);    
                }
            }
        }
    }
}
int main()
{
    Solve();
    system("pause");
    return 0;
}
/*
1
4 2 1 3 4
2 2 4 3 1
4 3 1 4 2
4 3 4 2 1
2 3 1 2 4
*/