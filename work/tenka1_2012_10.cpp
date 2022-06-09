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
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	string s; cin >> s;
	ll n = s.size();
	vector<string> cards;
	string t;
	map<ll, string> a; a[0] = "S"; a[1] = "H"; a[2] = "D"; a[3] = "C";
	map<ll, string> b; b[0] = "10"; b[1] = "J"; b[2] = "Q"; b[3] = "K"; b[4] = "A";
	rep(i, n) {
		if(s[i] == 'S' || s[i] == 'H' || s[i] == 'D' || s[i] == 'C') {
			cards.push_back(t); t = ""; t.push_back(s[i]);
		}else{
			t.push_back(s[i]);
		}
	}
	if(!t.empty()) cards.push_back(t); //末端処理
	ll ans_m = -1, ans_minid = INF;
	rep(i, 4) {
		bool flag = true; ll maxid = -1;
		rep(j, 5) {
			flag &= find(all(cards), a[i] + b[j]) != cards.end();
			chmax(maxid, (ll)(find(all(cards), a[i] + b[j]) - cards.begin()));
		}
		if(flag && maxid < ans_minid) ans_m = i, ans_minid = maxid;
	}
	string ans;
	rep(i, ans_minid) {
		bool flag = false;
		rep(j, 5) flag |= cards[i] == a[ans_m] + b[j];
		if(!flag)ans += cards[i];
	}
	cout << (ans.empty() ? "0" : ans) << endl;
}