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

vll dx = {1, -1, 1, -1};
vll dy = {1, 1, -1, -1};

ll n, ax, ay, bx, by;
vector<string> s;

bool check(ll x, ll y) {
	return 0 <= x && x < n && 0 <= y && y < n && s[x][y] == '.';
}

int main() {
	cin >> n >> ax >> ay >> bx >> by; ax--; ay--; bx--; by--;
	s.resize(n); rep(i, n) cin >> s[i];
	vvvll d(n, vvll(n, vll(4, INF)));
	vvll done(n, vll(n));
	deque<pair<pair<ll, ll>, ll>> dq; //x座標、y座標、向き
	rep(i, 4) { //初期値
		ll nx = ax + dx[i], ny = ay + dy[i];
		if(!check(nx, ny)) continue;
		d[nx][ny][i] = 1;
		dq.push_back({{nx, ny}, i});
	}
	
}