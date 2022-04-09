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
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	string s; ll k; cin >> s >> k;
	ll n = s.size();
	vll a; ll ans = 0;
	a.push_back(1);
	rep(i, n - 1) {
		if(s[i + 1] == s[i]) a.back()++;
		else a.push_back(1);
	}

	if(a.size() == 1) { //コーナー
		cout << n * k / 2 << endl; return 0;
	}

	if(s.front() != s.back()) {
		for(auto au : a) ans += au / 2;
		ans *= k;
	}else{
		ans += (a.front() + a.back()) / 2 * (k - 1); //連結部分
		ans += a.front() / 2 + a.back() / 2; //左端、右端
		ll tm = 0;
		for(ll i = 1; i < a.size() - 1; i++) tm += a[i] / 2;
		ans += tm * k;
	}
	cout << ans << endl;
}