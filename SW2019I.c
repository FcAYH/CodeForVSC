#include<stdio.h>

const int Maxn=1000010;
int t;
//char a[Maxn],b[Maxn];
void sub(float x,float *y,float *z)
{
    *y=*y-1.0;
    *z=*z+x;
}
void Solve()
{
    float a=2.5,b=9.0,*pa,*pb;
    pa=&a; pb=&b;
    sub(b-a,pa,pa);
    printf("%f\n",a);
    //Lhswez(1.1,2);
    //printf("ss");
    //for(int a=0,b=0;a<3&&b!=3;a++,b+=2) a++,cout<<"s"<<endl;
    /*
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
        scanf("%s",a+1),scanf("%s",b+1);
        int len1=strlen(a+1),len2=strlen(b+1),cnt=0;
        int ans=(a[1]-'0')^(b[1]-'0');
        for(int i=2;i<=len2;i++) ans^=(a[i]-'0')^(b[i]-'0');
        if(!ans) cnt++;
        for(int i=len2+1;i<=len1;i++)
        {
            ans^=(a[i-len2]-'0')^(a[i]-'0');
            if(!ans) cnt++;
        }
        printf("%d\n",cnt);
    }*/
}
int main()
{
    //freopen("string8.in","r",stdin);
    //freopen("string8.out","w",stdout);
    Solve();
    for(int i=1;i<=1000000000;i++);
    return 0;
}