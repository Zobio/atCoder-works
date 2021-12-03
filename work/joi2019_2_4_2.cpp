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
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

vvll g(10);
ll m, r;
ll ans = INF;

void dfs(ll co, ll cnt, ll num) {
	cout << co << " " << cnt << " " << num << " " << ans << endl; 
	if(cnt > ans || to_string(num).size() == 19) return; //やっても意味ない
	if(num != -1 && ((num - r + m) % m == 0)) chmin(ans, cnt); //最小値更新
	fore(a, g[co]) {
		ll change = num == -1 ? co : stoll(to_string(num) + to_string(co));
		dfs(a, cnt + 2, change);//押した
		dfs(a, cnt + 1, num);	//押さなかった
	}
	if(co != 0 || num != 0) dfs(co, cnt + 1, stoll(to_string(num) + to_string(co)));
}

int main() {
	cin >> m >> r;
	g[0].push_back(1);
	g[1].push_back(2); g[1].push_back(4);
	g[2].push_back(1); g[2].push_back(3); g[2].push_back(5);
	g[3].push_back(2); g[3].push_back(6);
	g[4].push_back(2); g[4].push_back(5); g[4].push_back(7);
	g[5].push_back(2); g[5].push_back(4); g[5].push_back(6); g[5].push_back(8);
	g[6].push_back(3); g[6].push_back(5); g[6].push_back(9);
	g[7].push_back(4); g[7].push_back(8);
	g[8].push_back(5); g[8].push_back(7); g[8].push_back(9);
	g[9].push_back(6); g[9].push_back(8);
	dfs(0, 0, -1); //場所、回数、出来た数
}