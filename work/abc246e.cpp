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

int main() {
	ll n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by; ax--; ay--; bx--; by--;
	vector<string> s(n); rep(i, n) cin >> s[i];
	vvvll d(n, vvll(n, vll(4, INF)));
	vector<vector<vector<bool>>> done(n, vector<vector<bool>>(n, vector<bool>(4, false)));
	deque<pair<pll, ll>> dq;
	rep(i, 4) { //初期値
		ll nx = ax + dx[i], ny = ay + dy[i];
		if(!(0 <= nx && nx < n)) continue;
		if(!(0 <= ny && ny < n)) continue;
		if(s[nx][ny] == '#') continue;
		d[nx][ny][i] = 1;
		dq.push_back({{nx, ny}, i});
	}
	while(!dq.empty()){
		pair<pll, ll> od = dq.front(); dq.pop_front();
		if(od.first == make_pair(bx, by)){cout << d[bx][by][od.second] << endl; return 0;}
		ll cx = od.first.first, cy = od.first.second;
		if(done[cx][cy][od.second]) continue;
		done[cx][cy][od.second] = true;
		ll cd = d[cx][cy][od.second];
		rep(i, 4) {
			ll nx = cx + dx[i], ny = cy + dy[i];
			if(!(0 <= nx && nx < n)) continue;
			if(!(0 <= ny && ny < n)) continue;
			if(s[nx][ny]=='#') continue;
			ll nd = cd + (i != od.second);
			if(d[nx][ny][i] > nd){
				d[nx][ny][i] = nd;
				if(i == od.second) dq.push_front({{nx, ny}, i}); //コストは変わらない
				else dq.push_back({{nx, ny},i}); //コストが1増えている
			}
		}
 	}
	cout << -1 << endl;
}