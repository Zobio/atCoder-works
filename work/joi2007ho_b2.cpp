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
	ll n, k; cin >> n >> k;
	bool exist0 = false;
	vll a(k); rep(i, k) {cin >> a[i]; if(a[i] == 0) exist0 = true;}
	sort(all(a));
	if(exist0) {
		rep(i, k - 1) a[i] = a[i + 1]; a.pop_back(); k--; //0のカードを抜く
	}
	vll b(k - 1); rep(i, k - 1) b[i] = a[i + 1] - a[i]; //aの階差数列
	vll rui(k); rep(i, k - 1) rui[i + 1] = rui[i] + b[i]; //bの累積和
	ll ans = 0, r = 0;
	rep(l, k) {//尺取り法
		while(r < k && rui[r] - rui[l] <= r - l + exist0) r++;
		chmax(ans, r - l + exist0); //白紙のカードがあるなら使う(仮に使わなくても良い場合もその部分列の末尾か先頭に付けることで長さを1増やすことができる)
	}
	cout << ans << endl;
}