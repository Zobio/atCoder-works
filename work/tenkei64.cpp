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
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, q; cin >> n >> q;
	vll a(n); rep(i, n) cin >> a[i];
	vector<pair<pair<ll,ll>, ll>> change(q);
	rep(i, q) {
		ll l, r, v; cin >> l >> r >> v; l--; r--;
		change[i] = {{l, r}, v};
	}
	ll ans = 0;
	rep(i, n - 1) ans += abs(a[i] - a[i + 1]);
	vll res;
	for(auto ch : change) { //左右の差分を計算していってansを変えていく
		ll l = ch.first.first, r = ch.first.second, v = ch.second;
		if(l > 0) { //l == 0だったら左側で不便さの変化は起こらない
			if((a[l - 1] <= a[l]) == (v >= 0)) ans += abs(v); //差が広がる
			else ans -= abs(a[l] - v); //差が縮まる
		}
		if(r < n - 1) { //r == n - 1だったら右側で不便さの変化は起こらない
			if((a[r] >= a[r + 1]) == (v >= 0)) ans += abs(v);//差が広がる
			else ans -= abs(a[l] - v);//差が縮まる
		}
		res.push_back(ans);
	}
	for(auto au : res) cout << au << endl;
}