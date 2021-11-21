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
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll N = 1ll << 20; //定数
	vll a(N, -1);
	ll q; cin >> q;
	ll h; set<ll> can; //"まだ要素が-1である地点の集合"
	rep(i, 1ll << 20) can.insert(i); //最初は全て-1
	rep(i, q) {
		ll t, x; cin >> t >> x;
		if(t == 1) {
			h = x % N;
			auto p = can.lower_bound(h); //1番近いところから選ぶ
			if(p == can.end()) p = can.lower_bound(0);
			//もしx%N ~ N-1の範囲で見つかっていなかったら0~x%N-1の範囲で探す("この問題の制約下でこの操作が有限回で終了することは証明できる"からこれが失敗することはない)
			a[*p] = x;
			can.erase(p);
		}else{
			cout << a[x % N] << endl;
		}
	}
}