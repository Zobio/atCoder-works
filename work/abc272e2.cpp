#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for(long long i = a; i < b; i++)
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
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	//n回操作したときの値の集合が分かればいい
	ll n, m; cin >> n >> m;
	vll a(n); rep(i, n) cin >> a[i];
	vvll vals(m + 1); //vals[i] = {a1, a2, a3...}: i回操作したときの値の集合はa1, a2, a3...
	rep(i, n) {
		if(a[i] >= n) continue;
		ll st = (a[i] >= 0 ? 1 : (-a[i] + (i + 1) - 1) / (i + 1)); //開始の回数は、aが負の時は0じゃない(切り上げ)
		ll en = min(m + 1, ((n - a[i]) + (i + 1) - 1) / (i + 1)); //終了回数は、min(m+1, n-(初期値)より1個前の値までの必要回数(切り上げ))
		for(int j = st; j < en; j++) {
            vals[j].push_back(a[i] + (i + 1) * j);
        }
	}

	reps(i, m) {
		ll sz = vals[i].size();
		vector<bool> exi(sz + 1);
		for(auto v: vals[i]) if(v < sz) exi[v] = true;
		ll res = 0;
		while(exi[res]) res++;
		cout << res << endl;
	}
}