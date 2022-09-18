#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <algorithm>
#include <cstring>
using namespace std;
const int Maxn=200010;
int n,num=0;
int p[Maxn];
int Num[Maxn];
int vis[Maxn];
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
    inline int max (int a, int b) 
    {
        return a > b ? a : b;
    }
    inline int min (int a, int b) 
    {
        return a < b ? a : b;
    }
    std :: vector <int> c;
    Int () {} typedef long long LL;
    Int (int x) {for (; x > 0; c.push_back (x % Big_B), x /= Big_B);}
    Int (LL x) {for (; x > 0; c.push_back (x % Big_B), x /= Big_B);}
    inline void CrZ () { for (; !c.empty () && c.back () == 0; c.pop_back ());}
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
    inline Int &operator /= (const Int &rhs) {return *this = div (rhs);}
    inline Int &operator %= (const Int &rhs) {return div (rhs), *this;}
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
        for (i = c.size () - rhs.c.size (); i >= 0; -- i) {
            r.shlb ();
            r += c[i];
            if (r.Comp (rhs) < 0) q.c[i] = 0;
            else {
                _l = 0, _r = Big_B;
                for (; _l != _r; ) {
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
        else {
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
    friend inline bool operator < (const Int &lhs, const Int &rhs) 
    {
        return lhs.Comp (rhs) < 0;
    }
    friend inline bool operator <= (const Int &lhs, const Int &rhs) 
    {
        return lhs.Comp (rhs) <= 0;
    }
    friend inline bool operator > (const Int &lhs, const Int &rhs) 
    {
        return lhs.Comp (rhs) > 0;
    }
    friend inline bool operator >= (const Int &lhs, const Int &rhs) 
    {
        return lhs.Comp (rhs) >= 0;
    }
    friend inline bool operator == (const Int &lhs, const Int &rhs) 
    {
        return lhs.Comp (rhs) == 0;
    }
    friend inline bool operator != (const Int &lhs, const Int &rhs) 
    {
        return lhs.Comp (rhs) != 0;
    }
#undef rg
};
Int gcd (Int a, Int b) 
{
	return b == 0 ? a : gcd (b, a % b); 
}
inline void Search(int x)
{
    int cnt=0;
    while(!vis[x])
    {
        vis[x]=1;
        cnt++;
        x=p[x];
    }
    Num[++num]=cnt;
}
void Solve()
{
    scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) if(!vis[i]) Search(i);
	Int ans=1;
	for(int i=1;i<=num;i++) ans=ans*Num[i]/gcd(ans,Num[i]);
	cout<<ans<<endl;
}
int main() 
{
    Solve();
    system("pause");
    return 0;
}
