//
//  main.cpp
//  H
//
//  Created by 徐润泽 on 2020/7/20.
//  Copyright © 2020 徐润泽. All rights reserved.
//
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int T;
bool p[200005];
struct node{
    int x, y;
};
int main(int argc, const char * argv[]) {
    for (int i = 2; i <= 450; i++) {
        if(!p[i]){
            for (int j = i * i; j <= 200000; j += i) {
                p[j] = 1;
            }
        }
    }
    cin>>T;
    while (T--) {
        int n, m = 0;
        node ans[100005];
        cin>>n;
        bool b[200005], c[200005];
        vector<int>f[200005];
        for (int i = 2; i <= n; i++) {
            b[i] = 0;
            c[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            if(!p[i]){
                for (int j = i; j <= n; j += i) {
                    if(!b[j]){
                        f[i].push_back(j);
                        b[j] = 1;
                    }
                }
            }
        }
        for (int i = 3; i <= n; i++) {
            if(!p[i]){
                int l = f[i].size();
                if(l % 2 == 1 && f[i][0] * 2 <= n){
                    ans[++m].x = f[i][0];
                    ans[m].y = f[i][0] * 2;
                    c[f[i][0] * 2] = 1;
                    for (int j = 1; j < l; j += 2) {
                        ans[++m].x = f[i][j];
                        ans[m].y = f[i][j + 1];
                    }
                }
                else{
                    for (int j = 0; j < l; j += 2) {
                        if(j + 1 < l){
                            ans[++m].x = f[i][j];
                            ans[m].y = f[i][j + 1];
                        }
                    }
                }
            }
        }
        bool flag = 0;
        int temp = 0;
        for (int i = 2; i <= n; i += 2) {
            if(!c[i]){
                if(!flag){
                    temp = i;
                    flag = 1;
                }
                else{
                    flag = 0;
                    ans[++m].x = temp;
                    ans[m].y = i;
                    c[temp] = 1;
                    c[i] = 1;
                }
            }
        }
        cout<<m<<endl;
        for (int i = 1; i <= m; i++) {
            printf("%d %d\n", ans[i].x, ans[i].y);
        }
    }
    system("pause");
    return 0;
}