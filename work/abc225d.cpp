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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, q; cin >> n >> q;
	vpll rel(n, {-1, -1}); //前、後の車両の番号を格納(存在しなければ-1)
	rep(_, q) {
		ll p; cin >> p;
		if(p == 1) {
			ll x, y; cin >> x >> y; x--; y--;
			rel[x].second = y;
			rel[y].first = x;
		}
		else if(p == 2) {
			ll x, y; cin >> x >> y; x--; y--;
			rel[x].second = -1;
			rel[y].first = -1;
		}
		else{
			ll x; cin >> x; x--;
			while(rel[x].second != -1) x = rel[x].second; //車両の末尾に移動
			ll cnt = 0;
			while(rel[x].first != -1) x = rel[x].first, cnt++; //先頭車両に移動
			cout << cnt + 1 << " " << x + 1 << " ";
			while(rel[x].second != -1) cout << rel[x].second + 1 << " ", x = rel[x].second;
			cout << endl;
		}
	}
}