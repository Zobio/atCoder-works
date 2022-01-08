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
	ll MA = 1000000;
	ll n, k; cin >> n >> k;
	bool exist0 = false;
	vll buc(MA + 10);
	rep(i, k) {ll a; cin >> a; buc[a]++; if(a == 0) exist0 = true;}
	ll ans = 0, p = 0; vll b;
	reps(i, MA) {
		if(buc[i]) p++;
		else if(p) b.push_back(p), p = 0;
	}
	if(p) b.push_back(p);
	if(!exist0) {
		rep(i, b.size()) chmax(ans, b[i]);
	}else{
		rep(i, b.size() - 1) chmax(ans, b[i + 1] + b[i] + 1); //+1は白紙のカード
	}
	cout << ans << endl;
}