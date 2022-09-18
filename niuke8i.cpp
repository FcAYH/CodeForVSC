#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
int T, Case=0;
int main(int argc, const char * argv[]) {
    cin>>T;
    while (T--) {
        int n;
        cin >> n;
        pair<int, int> a[100005];
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].first, &a[i].second);
            if(a[i].first > a[i].second) swap(a[i].first, a[i].second);
        }
        unordered_map<int, bool> vis;
        sort(a + 1, a + 1 + n);
        for(int i=1;i<=n;i++) printf("%d %d\n",a[i].first,a[i].second);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if(vis.find(a[i].first) == vis.end()){
                ans++;
                vis[a[i].first] = 1;
            }
            else if(vis.find(a[i].second) == vis.end()){
                ans++;
                vis[a[i].second] = 1;
            }
        }
        printf("Case #%d: %d\n", ++Case, ans);
    }
    system("pause");
    return 0;
}
/*
1
5
1 2
1 3
1 5 
3 4 
4 5

1 5 

1
5
1 2
1 6
1 4
2 5
2 6
*/