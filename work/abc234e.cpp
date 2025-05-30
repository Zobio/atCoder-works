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
	string n; cin >> n;
	ll siz = n.size();
	if(siz <= 2) {cout << n << endl; return 0;}
	if(siz >= 10) {
		string ans = ""; rep(i, siz) ans += n[0];
		rep(i, siz) cout << ((stoll(ans) >= stoll(n)) ? n[0] - '0' : n[0] + 1 - '0'); cout << endl;
		return 0;
	}
	ll x = stoll(n), safe = floor(9 / (siz - 1)); //safe:公差の最高値
	if(10 - safe * siz <= n[0] - '0') { //最初の桁がすでに大きすぎたときは公費がマイナスの等差数のなかから最小であるものを選んでいく
		ll st = max(siz - 1, (ll)n[0] - '0');
		safe = floor((st - 1) / (siz - 1));
		string ret; rep(i, siz) ret.push_back('0' + st), st -= safe;
		rep(i, siz) cout << (stoll(ret) < x ? ret[i] + 1 - '0' : ret[i] - '0'); cout << endl;
	}
}