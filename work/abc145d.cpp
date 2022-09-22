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
#define MOD 1000000007LL
#define mint modint1000000007
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template<typename T>
T nCr(T n, T r) {
	T ret = 1;
	for(T i = 0; i.val() < r.val(); i++) {
		ret *= n - i;
		ret /= i + 1;
	}
	return ret;
}

int main() {
	//(i + 1, j + 2), (i + 2, j + 1)
	ll x, y; cin >> x >> y;
	ll d = y - x; //dが操作1と操作2の回数の差
	ll need = (x + y) / 3; //必要な操作回数
	ll l = -1, r = 1000000010;
	while(r - l > 1) {
		ll mid = (l + r) / 2;
		pll sum = {1 * mid + 2 * (mid - d), 2 * mid + 1 * (mid - d)};
		if(sum.first <= x && sum.second <= y) l = mid;
		else r = mid;
	}
	if(make_pair(1 * l + 2 * (l - d), 2 * l + 1 * (l - d)) != make_pair(x, y)) {cout << 0 << endl; return 0;}
	cout << nCr((mint)need, (mint)l).val() << endl;
}