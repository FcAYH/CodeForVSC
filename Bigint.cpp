#include<bits/stdc++.h>
using namespace std;
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
class BigNum
{
private:
    int a[500]; //可以控制大数的位数
    int len;
public:
    BigNum(){len=1;memset(a,0,sizeof(a));} //构造函数
    BigNum(const int); //将一个 int 类型的变量转化成大数
    BigNum(const char*); //将一个字符串类型的变量转化为大数
    BigNum(const BigNum &); //拷贝构造函数
    BigNum &operator=(const BigNum &); //重载赋值运算符，大数之间进行赋值运算
    friend istream& operator>>(istream&,BigNum&); //重载输入运算符
    friend ostream& operator<<(ostream&,BigNum&); //重载输出运算符
    BigNum operator+(const BigNum &)const; //重载加法运算符，两个大数之间的相加运算
    BigNum operator-(const BigNum &)const; //重载减法运算符，两个大数之间的相减运算
    BigNum operator*(const BigNum &)const; //重载乘法运算符，两个大数之间的相乘运算
    BigNum operator/(const int &)const; //重载除法运算符，大数对一个整数进行相除运算
    BigNum operator^(const int &)const; //大数的 n 次方运算
    int operator%(const int &)const; //大数对一个类型的变量进行取模运算int
    bool operator>(const BigNum &T)const; //大数和另一个大数的大小比较
    bool operator>(const int &t)const; //大数和一个 int 类型的变量的大小比较
    void print(); //输出大数
};
//将一个 int 类型的变量转化为大数
BigNum::BigNum(const int b)
{
    int c,d=b;
    len=0;
    memset(a,0,sizeof(a));
    while(d>MAXN)
    {
        c=d-(d/(MAXN+1))*(MAXN+1);
        d=d/(MAXN+1);
        a[len++]=c;
    }
    a[len++]=d;
}
//将一个字符串类型的变量转化为大数
BigNum::BigNum(const char *s)
{
    int t,k,index,L,i;
    memset(a,0,sizeof(a));
    L=strlen(s);
    len=L/DLEN;
    if(L%DLEN)len++;
    index=0;
    for(i=L-1;i>=0;i-=DLEN)
    {
        t=0;
        k=i-DLEN+1;
        if(k<0)k=0;
        for(int j=k;j<=i;j++)
        t=t*10+s[j]-'0';
        a[index++]=t;
    }
}
//拷贝构造函数
BigNum::BigNum(const BigNum &T):len(T.len)
{
    int i;
    memset(a,0,sizeof(a));
    for(i=0;i<len;i++)
    a[i]=T.a[i];
}
//重载赋值运算符，大数之间赋值运算
BigNum & BigNum::operator=(const BigNum &n)
{
    int i;
    len=n.len;
    memset(a,0,sizeof(a));
    for(i=0;i<len;i++)
    a[i]=n.a[i];
    return *this;
}
istream& operator>>(istream &in,BigNum &b)
{
    char ch[MAXSIZE*4];
    int i=-1;
    in>>ch;
    int L=strlen(ch);
    int count=0,sum=0;
    for(i=L-1;i>=0;)
    {
        sum=0;
        int t=1;
        for(int j=0;j<4&&i>=0;j++,i--,t*=10)
        {
            sum+=(ch[i]-'0')*t;
        }
        b.a[count]=sum;
        count++;
    }
    b.len=count++;
    return in;
}
//重载输出运算符
ostream& operator<<(ostream& out,BigNum& b)
{
    int i;
    cout<<b.a[b.len-1];
    for(i=b.len-2;i>=0;i--)
    {
        printf("%04d",b.a[i]);
    }
    return out;
}
 //两个大数之间的相加运算
BigNum BigNum::operator+(const BigNum &T)const
{
    BigNum t(*this);
    int i,big;
    big=T.len>len?T.len:len;
    for(i=0;i<big;i++)
    {
        t.a[i]+=T.a[i];
        if(t.a[i]>MAXN)
        {
            t.a[i+1]++;
            t.a[i]-=MAXN+1;
        }
    }
    if(t.a[big]!=0) t.len=big+1;
    else t.len=big;
    return t;
}
//两个大数之间的相减运算
BigNum BigNum::operator-(const BigNum &T)const
{
    int i,j,big;
    bool flag;
    BigNum t1,t2;
    if(*this>T)
    {
        t1=*this;
        t2=T;
        flag=0;
    }
    else
    {
        t1=T;
        t2=*this;
        flag=1;
    }
    big=t1.len;
    for(i=0;i<big;i++)
    {
        if(t1.a[i]<t2.a[i])
        {
            j=i+1;
            while(t1.a[j]==0) j++;
            t1.a[j--]--;
            while(j>i) t1.a[j--]+=MAXN;
            t1.a[i]+=MAXN+1-t2.a[i];
        }
        else t1.a[i]-=t2.a[i];
    }
    t1.len=big;
    while(t1.a[t1.len-1]==0 && t1.len>1)
    {
        t1.len--;
        big--;
    }
    if(flag) t1.a[big-1]=0-t1.a[big-1];
    return t1;
}
//两个大数之间的相乘
BigNum BigNum::operator*(const BigNum &T)const
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i=0;i<len;i++)
    {
        up=0;
        for(j=0;j<T.len;j++)
        {
            temp=a[i]*T.a[j]+ret.a[i+j]+up;
            if(temp>MAXN)
            {
                temp1=temp-temp/(MAXN+1)*(MAXN+1);
                up=temp/(MAXN+1);
                ret.a[i+j]=temp1;
            }
            else
            {
                up=0;
                ret.a[i+j]=temp;
            }
        }
        if(up!=0)
        ret.a[i+j]=up;
    }
    ret.len=i+j;
    while(ret.a[ret.len-1]==0 && ret.len>1) ret.len--;
    return ret;
}
//大数对一个整数进行相除运算
BigNum BigNum::operator/(const int &b)const
{
    BigNum ret;
    int i,down=0;
    for(i=len-1;i>=0;i--)
    {
        ret.a[i]=(a[i]+down*(MAXN+1))/b;
        down=a[i]+down*(MAXN+1)-ret.a[i]*b;
    }
    ret.len=len;
    while(ret.a[ret.len-1]==0 && ret.len>1) ret.len--;
    return ret;
}
    //大数对一个 int 类型的变量进行取模
int BigNum::operator%(const int &b)const
{
    int i,d=0;
    for(i=len-1;i>=0;i--) d=((d*(MAXN+1))%b+a[i])%b;
    return d;
}
//大数的 n 次方运算
BigNum BigNum::operator^(const int &n)const
{
    BigNum t,ret(1);
    int i;
    if(n<0)exit(-1);
    if(n==0)return 1;
    if(n==1)return *this;
    int m=n;
    while(m>1)
    {
        t=*this;
        for(i=1;(i<<1)<=m;i<<=1) t=t*t;
        m-=i;
        ret=ret*t;
        if(m==1) ret=ret*(*this);
    }
    return ret;
}
//大数和另一个大数的大小比较
bool BigNum::operator>(const BigNum &T)const
{
    int ln;
    if(len>T.len)return true;
    else if(len==T.len)
    {
        ln=len-1;
        while(a[ln]==T.a[ln]&&ln>=0) ln--;
        if(ln>=0 && a[ln]>T.a[ln]) return true;
        else return false;
    }
    else return false;
}
//大数和一个 int 类型的变量的大小比较
bool BigNum::operator>(const int &t)const
{
    BigNum b(t);
    return *this>b;
}
//输出大数
void BigNum::print()
{
    int i;
    printf("%d",a[len-1]);
    for(i=len-2;i>=0;i--) printf("%04d",a[i]);
    printf("\n");
}
BigNum a,b;
int main()
{
    cin>>a>>b;
    BigNum c;
    c=a+b;
    c.print();
    c=a-b;
    c.print();
    c=a*b;
    c.print();
    
    return 0;
}

//------------------------------------------------------------------------------------------------------

const int Big_B = 1000000000;
const int Big_L = 9;
inline int intcmp_ (int a, int b) 
{
    if (a > b) return 1;
    return a < b ? -1 : 0;
}
struct Int 
{
#define rg register
    inline int max (int a, int b) {	return a > b ? a : b; }
    inline int min (int a, int b) { return a < b ? a : b; }
    std :: vector <int> c;
    Int () {} typedef long long LL;
    Int (int x) { for (; x > 0; c.push_back (x % Big_B), x /= Big_B); }
    Int (LL x) { for (; x > 0; c.push_back (x % Big_B), x /= Big_B); }
    inline void CrZ () { for (; !c.empty () && c.back () == 0; c.pop_back ()); }
    inline Int &operator += (const Int &rhs) 
    {
        c.resize (max (c.size (), rhs.c.size ()));
        rg int i, t = 0, S;
        for (i = 0, S = rhs.c.size (); i < S; ++ i)
            c[i] += rhs.c[i] + t, t = c[i] >= Big_B, c[i] -= Big_B & (-t);
        for (i = rhs.c.size (), S = c.size (); t && i < S; ++ i)
            c[i] += t, t = c[i] >= Big_B, c[i] -= Big_B & (-t);
        if (t) c.push_back (t);
        return *this;
    }
    inline Int &operator -= (const Int &rhs) 
    {
        c.resize (max (c.size (), rhs.c.size ()));
        rg int i, t = 0, S;
        for (i = 0, S = rhs.c.size (); i < S; ++ i)
            c[i] -= rhs.c[i] + t, t = c[i] < 0, c[i] += Big_B & (-t);
        for (i = rhs.c.size (), S = c.size (); t && i < S; ++ i)
            c[i] -= t, t = c[i] < 0, c[i] += Big_B & (-t);
        CrZ ();
        return *this;
    }
    inline Int &operator *= (const Int &rhs) 
    {
        rg int na = c.size (), i, j, S, ai;
        c.resize (na + rhs.c.size ());
        LL t;
        for (i = na - 1; i >= 0; -- i) 
        {
            ai = c[i], t = 0, c[i] = 0;
            for (j = 0, S = rhs.c.size (); j < S; ++ j) 
            {
                t += c[i + j] + (LL) ai * rhs.c[j];
                c[i + j] = t % Big_B, t /= Big_B;
            }
            for (j = rhs.c.size (), S = c.size (); t != 0 && i + j < S; ++ j)
                t += c[i + j], c[i + j] = t % Big_B, t /= Big_B;
            assert (t == 0);
        }
        CrZ ();
        return *this;
    }
    inline Int &operator /= (const Int &rhs) { return *this = div (rhs); }
    inline Int &operator %= (const Int &rhs) { return div (rhs), *this;  }
    inline Int &shlb (int l = 1) 
    {
        if (c.empty ()) return *this;
        c.resize (c.size () + l);
        rg int i;
        for (i = c.size () - 1; i >= l; -- i) c[i] = c[i - l];
        for (i = 0; i < l; ++ i) c[i] = 0;
        return *this;
    }
    inline Int &shrb (int l = 1) 
    {
        for (rg int i = 0; i < c.size () - l; ++ i) c[i] = c[i + l];
        c.resize (max (c.size () - l, 0));
        return *this;
    }
    inline int Comp (const Int &rhs) const 
    {
        if (c.size () != rhs.c.size ()) return intcmp_ (c.size (), rhs.c.size ());
        for (rg int i = c.size () - 1; i >= 0; -- i)
            if (c[i] != rhs.c[i]) return intcmp_ (c[i], rhs.c[i]);
        return 0;
    }
    inline Int div (const Int &rhs) 
    {
        assert (!rhs.c.empty ());
        Int q, r;
        rg int i;
        if (rhs > *this) return 0;
        q.c.resize (c.size () - rhs.c.size () + 1);
        rg int _l, _r, mid;
        for (i = c.size () - 1; i > c.size () - rhs.c.size (); -- i) r.shlb (), r += c[i];
        for (i = c.size () - rhs.c.size (); i >= 0; -- i) 
        {
            r.shlb ();
            r += c[i];
            if (r.Comp (rhs) < 0) q.c[i] = 0;
            else 
            {
                _l = 0, _r = Big_B;
                for (; _l != _r; ) 
                {
                    mid = _l + _r >> 1;
                    if ((rhs * mid).Comp (r) <= 0) _l = mid + 1;
                    else _r = mid;
                }
                q.c[i] = _l - 1, r -= rhs * q.c[i];
            }
        }
        q.CrZ (), *this = r;
        return q;
    }
    friend inline Int operator + (const Int &lhs, const Int &rhs) 
    {
        Int res = lhs;
        return res += rhs;
    }
    friend inline Int operator - (const Int &lhs, const Int &rhs) 
    {
        Int res = lhs;
        return res -= rhs;
    }
    friend inline Int operator * (const Int &lhs, const Int &rhs) 
    {
        Int res = lhs;
        return res *= rhs;
    }
    friend inline Int operator / (const Int &lhs, const Int &rhs) 
    {
        Int res = lhs;
        return res.div (rhs);
    }
    friend inline Int operator % (const Int &lhs, const Int &rhs) 
    {
        Int res = lhs;
        return res.div (rhs), res;
    }
    friend inline std :: ostream &operator << (std :: ostream &out, const Int &rhs) 
    {
        if (rhs.c.size () == 0) out << "0";
        else 
        {
            out << rhs.c.back ();
            for (rg int i = rhs.c.size () - 2; i >= 0; -- i)
                out << std :: setfill ('0') << std :: setw (Big_L) << rhs.c[i];
        }
        return out;
    }
    friend inline std :: istream &operator >> (std :: istream &in, Int &rhs) 
    {
        static char s[10000];
        in >> s + 1;
        int Len = strlen (s + 1);
        int v = 0;
        LL r = 0, p = 1;
        for (rg int i = Len; i >= 1; -- i) 
        {
            ++ v;
            r = r + (s[i] - '0') * p, p *= 10;
            if (v == Big_L) rhs.c.push_back (r), r = 0, v = 0, p = 1;
        }
        if (v != 0) rhs.c.push_back (r);
        return in;
    }
    friend inline bool operator < (const Int &lhs, const Int &rhs) { return lhs.Comp (rhs) < 0; }
    friend inline bool operator <= (const Int &lhs, const Int &rhs) { return lhs.Comp (rhs) <= 0; }
    friend inline bool operator > (const Int &lhs, const Int &rhs) { return lhs.Comp (rhs) > 0; }
    friend inline bool operator >= (const Int &lhs, const Int &rhs) { return lhs.Comp (rhs) >= 0; }
    friend inline bool operator == (const Int &lhs, const Int &rhs) { return lhs.Comp (rhs) == 0; }
    friend inline bool operator != (const Int &lhs, const Int &rhs) { return lhs.Comp (rhs) != 0; }
#undef rg
};
int Main () 
{
    return 0;
}
int ZlycerQan = Main ();
int main (int argc, char *argv[]) 
{
}