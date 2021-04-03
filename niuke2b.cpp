#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
  
struct Point{
    LL x, y;
    Point(LL x=0, LL y=0):x(x),y(y){}
    bool operator<(const Point&t)const{
        if(x!=t.x) return x<t.x;
        return y<t.y;
    }
    bool operator==(const Point&t)const{
        return (!(*this<t))&&(!(t<*this));
    }
};
  
const int N=2020;
  
Point p[N], resp, z[N*N]; int cnt=0;
int n, resn=0;
 
bool check(Point &a, Point &b){
    return a.x*b.y==a.y*b.x;
}
 
Point getCir(Point &a, Point &b){
    double c_x=(a.x*a.x*b.y+a.y*a.y*b.y-b.x*b.x*a.y-b.y*b.y*a.y)/2.0\
        /(a.x*b.y-b.x*a.y);
    Point t;
    if(a.y!=0ll) t=a;
    else t=b;
    double c_y=t.x*t.x/2.0/t.y+t.y/2.0-t.x*c_x/t.y;
    c_x*=1000000; c_y*=1000000;
    LL t_x=c_x, t_y=c_y;
    return Point(t_x,t_y);
}
  
int main(){
    scanf("%d", &n);
    for(int i=1, t1, t2; i<=n; ++i){
        scanf("%d%d", &t1, &t2);
        p[i]=Point(t1,t2);
    }
    if(n==1){
        printf("1\n");
        return 0;
    }
    bool flag=false;
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            if(check(p[i],p[j])) continue;
            flag=true;
            z[++cnt]=getCir(p[i],p[j]);
        }
    }
    if(!flag){
        printf("1\n");
        return 0;
    }
    sort(z+1,z+cnt+1); int cur=1;
    for(int i=2; i<=cnt; ++i){
        if(z[i]==z[i-1]) cur++;
        else{
            resn=max(resn,cur);
            cur=1;
        }
    }
    resn=max(resn,cur)*2;
    for(int i=2; i<=n; ++i){
        if(i*i>resn){
            printf("%d\n", i);
            return 0;
        }
    }
}