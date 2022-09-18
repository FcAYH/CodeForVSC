#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int T, lg[100001], p[18][100005], Case;
__int128_t f[18][100005];
int getMax(int l, int r){
    int k = lg[r - l + 1];
    if(f[k][l] > f[k][r - (1 << k) + 1]) return p[k][l];
    else return p[k][r - (1 << k) + 1];
}
void print(__int128_t x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int main(int argc, const char * argv[]) {
    for (int i = 2; i <= 100000; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    cin>>T;
    while (T--) {
        int n;
        cin>>n;
        int a[100005], b[100005];
        __int128_t s[100005];
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            s[i] = s[i - 1] + a[i];
            f[0][i] = s[i];
            p[0][i] = i;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            b[i] = i == 1 ? b[i] : min(b[i - 1], b[i]);
        }

        int cur = n, tot = 0;
        __int128_t ans = 0;
        while (cur) {
            int po = getMax(1, cur);
            ans += s[po] * (b[po] - tot);
            tot += b[po] - tot;
            cur = po - 1;
        }
        printf("Case #%d: %d ", ++Case, b[1]);
        print(ans);
        cout<<endl;
    }
    return 0;
}