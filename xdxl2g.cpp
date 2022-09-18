#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int t;
ll X1,Y1,w1,h1,X2,Y2,w2,h2;
ll S,S1,S2;
struct Point{ll x,y;}poi[10];
inline void Make_Rec()
{
    poi[1].x=X1,poi[1].y=Y1;
    poi[2].x=X1,poi[2].y=Y1+h1;
    poi[3].x=X1+w1,poi[3].y=Y1+h1;
    poi[4].x=X1+w1,poi[4].y=Y1;
    poi[5].x=X2,poi[5].y=Y2;
    poi[6].x=X2,poi[6].y=Y2+h2;
    poi[7].x=X2+w2,poi[7].y=Y2+h2;
    poi[8].x=X2+w2,poi[8].y=Y2;
    S1=h1*w1,S2=h2*w2;
    if(poi[1].x<=poi[5].x&&poi[1].y<=poi[5].y)
    {
        if(poi[2].y<=poi[5].y) S=0;
        else if(poi[3].x<=poi[5].x) S=0;
        else
        {
            if(poi[7].x>=poi[3].x&&poi[7].y>=poi[3].y&&poi[5].x<=poi[1].x&&poi[5].y<=poi[1].y) S=S1;
            else if(poi[3].x>=poi[7].x&&poi[3].y>=poi[7].y) S=S2;
            else if(poi[2].y>=poi[6].y) S=h2*(poi[3].x-poi[5].x);
            else if(poi[8].x<=poi[4].x) S=w2*(poi[2].y-poi[5].y);
            else S=(poi[4].x-poi[5].x)*(poi[3].y-poi[5].y);
        }
    }
    else if(poi[1].x>poi[5].x&&poi[1].y<poi[5].y)
    {
        if(poi[8].x<=poi[1].x) S=0;
        else if(poi[8].y>=poi[2].y) S=0;
        else
        {
            if(poi[7].y<=poi[2].y&&poi[7].x<=poi[3].x) S=h2*(poi[8].x-poi[1].x);
            else if(poi[7].y<=poi[2].y&&poi[7].x>poi[3].x) S=h2*w1;
            else if(poi[7].x>poi[3].x&&poi[7].y>poi[3].y) S=w1*(poi[3].y-poi[5].y);
            else S=(poi[8].x-poi[1].x)*(poi[2].y-poi[8].y);
        }
    }
    else if(poi[1].x>=poi[5].x&&poi[1].y>=poi[5].y)
    {
        if(poi[8].x<=poi[1].x) S=0;
        else if(poi[7].y<=poi[1].y) S=0;
        else
        {
            if(poi[7].x>=poi[3].x&&poi[7].y>=poi[3].y) S=S1;
            else if(poi[7].y<poi[3].y&&poi[7].x>=poi[3].x) S=w1*(poi[7].y-poi[1].y);
            else if(poi[7].y>=poi[3].y&&poi[7].x<poi[3].x) S=h1*(poi[7].x-poi[1].x);
            else S=(poi[7].x-poi[1].x)*(poi[7].y-poi[1].y);
        }
    }
    else
    {
        if(poi[7].y<=poi[1].y) S=0;
        else if(poi[5].x>=poi[4].x) S=0;
        else
        {
            if(poi[7].x<=poi[4].x&&poi[7].y<=poi[3].y) S=w2*(poi[7].y-poi[1].y);
            else if(poi[7].x<=poi[4].x&&poi[7].y>poi[3].y) S=w2*h1;
            else if(poi[7].x>poi[3].x&&poi[7].y>poi[3].y) S=h1*(poi[3].x-poi[5].x);
            else S=(poi[4].x-poi[5].x)*(poi[7].y-poi[4].y);
        }
    }
    printf("%.2lf\n",(double)S/(double)(S1+S2-S));

}
/*
M(x,y), N(x, y+h), P(x+w, y+h), Q(x+w, y).
*/
void Solve()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&X1,&Y1,&w1,&h1);
        scanf("%lld%lld%lld%lld",&X2,&Y2,&w2,&h2);
        Make_Rec();
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


10000
1 1 2 2
2 1 2 2
1 1 5 5
1 2 7 1
1 1 2 2
2 2 2 2

1 1 2 2
1 1 2 1

1 0 4 4
0 1 9 9
*/