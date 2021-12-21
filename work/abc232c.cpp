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
	ll n, m; cin >> n >> m;
	vpll a(m), c(m);
	rep(i, m) {ll p, q; cin >> p >> q; p--; q--; if(p > q) swap(p, q); a[i] = {p, q};}
	rep(i, m) {ll p, q; cin >> p >> q; p--; q--; if(p > q) swap(p, q); c[i] = {p, q};}
	sort(all(a)); sort(all(c));
	vll per(n); iota(all(per), 0);
	do{
		vpll pa(m); vpll pc(m);
		rep(i, m) {
			pair<ll, ll> p1 = {min(per[a[i].first], per[a[i].second]), max(per[a[i].first], per.at(a[i].second))};
			pair<ll, ll> p2 = {c[i].first, c[i].second};
			pa[i] = p1; pc[i] = p2;
		}
		sort(all(pa)); sort(all(pc));
		bool flag = true;
		rep(i, m) if(pa[i] != pc[i]) flag = false;
		if(flag) {cout <<"Yes" << endl; return 0;}
	}while(next_permutation(all(per)));
	cout << "No" << endl;
}