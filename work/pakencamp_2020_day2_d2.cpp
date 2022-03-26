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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	vvll a(n), b(n);
	rep(i, n) {
		ll tmp; cin >> tmp;
		rep(j, tmp) {ll p; cin >> p; p--; a[i].push_back(p);}
		cin >> tmp;
		rep(j, tmp) {ll p; cin >> p; p--; b[i].push_back(p);}
		sort(all(a[i])); sort(all(b[i]));
	}
	vvll g(n); //g[i] = {i1, i2, i3...} iの後にi1, i2, i3...のショーをする必要がある
	rep(i, n) rep(j, a[i].size()) rep(k, n) {
		if(binary_search(all(b[k]), a[i][j])) g[k].push_back(i);
	}
	vll per(n); iota(all(per), 0);
	do{
		bool flag = true;
		rep(i, n) rep(j, i) {
			if(binary_search(all(g[per[i]]), per[j])) flag = false;
		}
		if(flag) {
			rep(i, n) cout << per[i] + 1 << (i == n - 1 ? "" : " "); cout << endl;
			return 0;
		}
	}while(next_permutation(all(per)));
	cout << -1 << endl;
}