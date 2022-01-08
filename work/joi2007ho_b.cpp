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
	bool flag = false;
	vll a(k); rep(i, k) {cin >> a[i]; if(a[i] == 0) flag = true;}
	sort(all(a));
	ll ans = 0, cnt = 1;
	if(!flag) {
		rep(i, k - 1) {
			if(a[i + 1] - a[i] == 1) cnt++;
			else chmax(ans, cnt), cnt = 1;
		}
		chmax(ans, cnt);
	}else{
		ll used = 0; //"白紙のカードを未使用" → used == 0
		for(ll i = 1; i < k - 1; i++) {
			if(a[i + 1] - a[i] == 1) cnt++;
			else if(a[i + 1] - a[i] == 2 && used == 0) cnt += 2, used = i; //"白紙のカード"を挟むので+=2
			else chmax(ans, cnt), i = used, cnt = 1, used = 0; //1番最後のカード
		}
		chmax(ans, cnt);
	}
	cout << ans << endl;
}