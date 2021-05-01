#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int n, a, b, c, ans = MOD;
vector<int> l;
vector<int> alst, blst, clst;

void dfs(int now) {
	if(now == n) {
		if(alst.empty() || blst.empty() || clst.empty()) return;
		int mp = 0;
		mp += 10 * (alst.size() + blst.size() + clst.size() - 3);
		vector<int> sums(3);
		for(int i = 0; i < alst.size(); i++) {
			sums[0] += alst[i];
		}
		for(int i = 0; i < blst.size(); i++) {
			sums[1] += blst[i];
		}
		for(int i = 0; i < clst.size(); i++) {
			sums[2] += clst[i];
		}
		sort(sums.begin(), sums.end());
		mp += abs(sums[2] - a) + abs(sums[1] - b) + abs(sums[0] - c);
		if(mp < ans) ans = mp;
		return;
	}
	alst.push_back(l[now]);
	dfs(now + 1);
	alst.pop_back();
	blst.push_back(l[now]);
	dfs(now + 1);
	blst.pop_back();
	clst.push_back(l[now]);
	dfs(now + 1);
	clst.pop_back();
	dfs(now + 1);
}

int main() {
	cin >> n >> a >> b >> c;
	l.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> l[i];
	}
	sort(l.begin(), l.end());
	dfs(0);
	cout << ans << endl;
}