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
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template<typename T>
vector<T> osa_k(T num) {
	/*
	1からnumについて、エラトステネスの篩を用いる。
	その際、配列retを生成する。
	ret[i] : iをふるい落とした最小の素数
	rey[i] == -1のときは、iは素数
	計算量はO(NloglogN)
	これを用いて、1からnumについてO(NlogN)で素因数の列挙ができる。(愚直な試し割りだとO(N√N))
	*/
	vector<T> ret(num + 1, -1); //ret[i] : その数をふるい落とした最小の素数
	for(T i = 2; i <= num; i++) {
		if(ret[i] != -1) continue; //すでにふるい落とされている(=素数でない)
		for(T j = i * 2; j <= num; j += i) {
			if(ret[j] == -1) ret[j] = i;
		}
	}
	return ret;
    
}

int main() {
	ll n, k; cin >> n >> k;
	vll d = osa_k(n);
	ll ans = 0;
	for(ll i = 2; i <= n; i++) {
		ll cur = i;
		set<ll> divs;
		while(d[cur] != -1) divs.insert(d[cur]), cur = cur / d[cur];
		divs.insert(cur);
		ans += divs.size() >= k;
	}
	cout << ans << endl;
}