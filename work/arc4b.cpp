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

int main() {
	//最小値は、三角形の成立条件を満たすのなら0,それ以外ならなるべく小さくとる?
	setcout(15);
	ll n; cin >> n;
	vll a(n);
	rep(i, n) cin >> a[i];
	while(n < 3) a.push_back(0), n++;
	vll rui(n + 1); rep(i, n) rui[i + 1] = rui[i] + a[i];
	ld ans = rui[n];
	//三角形が成立するような３辺の分け方を全探索すればいけそう?
	rep(i, n) reep(j, i + 1, n) reep(k, j + 1, n) {
		vll hen;
		hen.push_back(rui[i + 1] - rui[0]);
		hen.push_back(rui[j + 1] - rui[i + 1]);
		hen.push_back(rui[k + 1] - rui[j + 1]);
		sort(all(hen));
		if(hen[2] <= (hen[1] + hen[0])) ans = 0; 
		else chmin(ans, (ld)abs((hen[1] + hen[0] - hen[2])));
	}
	cout << rui[n] << endl;
	cout << ans << endl;
}