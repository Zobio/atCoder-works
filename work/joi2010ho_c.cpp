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
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, l; cin >> n >> l;
	vll a(n + 2); reps(i, n) cin >> a[i];
	vll dp(n + 2);
	reps(i, n) { //初期条件→自分の左右より長いつららのDP値を確定
		if (a[i] > a[i-1] && a[i] > a[i+1]) dp[i] = l - a[i];
	}
    reps(i, n) { //左からDP
        if (a[i] < a[i-1]) chmax(dp[i], dp[i - 1] + (l - a[i]));
    }
	rreps(i, n) { //右からDP
        if (a[i] < a[i+1]) chmax(dp[i], dp[i + 1] + (l - a[i]));
    }
	cout << *max_element(all(dp)) << endl;
}