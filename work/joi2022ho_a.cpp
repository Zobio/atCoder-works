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
	vll a(n); rep(i, n) cin >> a[i];
	vll cutted = a; //カットした後の長さを格納
	ll q; cin >> q;
	vll x(q); rep(i, q) cin >> x[i];
	vll div(n, 1); //aが何分割できるかを格納
	rep(i, n) {
		ll cur = a[i];
		while(cur % 2 == 0) div[i] *= 2, cur /= 2, cutted[i] /= 2;
	}
	vll rui_div(n + 1); //divの累積和
	rep(i, n) rui_div[i + 1] = rui_div[i] + div[i];
	rep(i, q) {
		ll p = lower_bound(all(rui_div), x[i]) - rui_div.begin();
		p--; //ずらす
		cout << cutted[p] << endl;
	}
}