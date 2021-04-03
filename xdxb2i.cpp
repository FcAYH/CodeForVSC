#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
const int MX = 3010, inf = 2e9;

int n, m, one;
vector<int> A;
vector<int> P[MX];
long long ans = 2e18;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int p, c; cin >> p >> c;
		P[p].push_back(c);
	}
	for (int i = 1; i <= m; i++) sort(P[i].begin(), P[i].end(), greater<int>());

	for (int x = 0; x <= n; x++) {
		int cnt = P[1].size(); long long sum = 0;
		A.clear();
		for (int i = 2; i <= m; i++) {
			int sz = P[i].size(), r = min(x, sz);
			for (int j = 0; j < r; j++) A.push_back(P[i][j]);
			for (int j = x; j < sz; j++) cnt++, sum += P[i][j];
		}
		sort(A.begin(), A.end());
		for (int y : A) {
			if (cnt <= x) cnt++, sum += y;
		}
		if (cnt <= x) continue;
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}