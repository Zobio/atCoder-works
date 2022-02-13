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

int main() { //11点解法
	setcout(15);
	ll n, k; cin >> n >> k;
	vector<pair<ld, ld>> a(n); rep(i, n) cin >> a[i].first >> a[i].second;
	sort(all(a));
	vll perm(n); iota(all(perm), 0);
	ld ans = INF;
	do{
		for(ll bits = 0; bits < (1ll << k); bits++) {
			ll p = 1; ld sum = 0;
			rep(i, k) {
				if((bits >> i) & 1 || a[perm[i]].second == -1) sum += a[perm[i]].first / p; //その地区で協力者を増やさない
				else sum += a[perm[i]].second / p, p++; //増やす
			}
			chmin(ans, sum);
		}
	}while(next_permutation(all(perm)));
	cout << ans << endl;
}