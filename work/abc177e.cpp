#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	map<int, int> div;
	rep(i, n) {
		int cur = a[i];
		set<int> ds; //curの約数の集合(重複回避)
		int pre = -1;
		while(cur > 1) {
			if(pre == cur) {ds.insert(cur); break;}
			pre = cur;
			for(int j = 2; j * j <= cur; j++) {
				if(cur % j == 0) ds.insert(j), cur /= j;
			}
		}
		for(auto au : ds) div[au]++;
	}
	bool flag1 = false, flag2 = false;
	for(auto au : div) {
		if(au.second == n) flag1 = true; //全体に共通の約数があるのでnot coprime 
		if(au.second >= 2) flag2 = true; //共通の約数がある2数が存在しているのでsetwise coprime
	}
	if(flag1) cout << "not coprime" << "\n";
	else if(flag2) cout << "setwise coprime" << "\n";
	else cout << "pairwise coprime" << "\n";
}