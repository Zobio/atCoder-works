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
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

bool check_arr(deque<ll> a, deque<ll> b) {
	rep(i, min(a.size(), b.size())) {
		if(a[i] != b[i]) return a[i] > b[i];
	}
	return a.size() > b.size();
}

int main() {
	ll n, k; cin >> n >> k;
	vector<deque<ll>> book(10);
	rep(i, n) {
		ll c, g; cin >> c >> g; g--;
		book[g].push_back(c);
	}
	rep(i, 10) sort(rall(book[i]));
	vector<deque<ll>> rui(10, deque<ll>(2010));
	rep(i, 10) rep(j, book[i].size()) { //累積和
		rui[i][j + 1] = rui[i][j] + book[i][j];
	}
	rep(i, 10) rep(j, book[i].size() + 1) {
		rui[i][j] += j * (j - 1); //同じジャンルなので料金を加算
	}
	vector<deque<ll>> pro(10); //その本を売った時の料金の加算分(つまりruiの階差数列)
	rep(i, 10) rep(j, book[i].size()) {
		pro[i].push_back(rui[i][j + 1] - rui[i][j]);
	}
	ll ans = 0;
	while(k--) {
		ll maxn = -1, maxid = -1;
		rep(i, 10) {
			if(pro[i].size() == 0) continue;
			if(chmax(maxn, pro[i].front())) maxid = i;
			else if(maxn == pro[i].front() && check_arr(pro[i], pro[maxid])) {
				maxid = i;
			}
		}
		ans += maxn;
		pro[maxid].pop_front();
	}
	cout << ans << endl;
}