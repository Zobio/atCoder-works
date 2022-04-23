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

struct vertex {
	ll num;
	ll parent; //親がいない場合は-1
	ll count; 
};

int main() {
	ll n; cin >> n;
	vvll g(n);
	rep(i, n - 1) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b); g[b].push_back(a);
	}
	vpll ans(n); rep(i, n) ans[i].first = INF, ans[i].second = -INF; //初期値
	ll leaf_cnt = 0;
	stack<vertex> que; que.push({0, -1, 1}); //現頂点番号,親の頂点番号,訪問回数
	while(!que.empty()) {
		vertex now = que.top(); que.pop();
		//訪問回数1回目なら、子を列挙
		if(now.count == 1) {
			que.push({now.num, now.parent, 2});
			//子を列挙
			for(auto au : g[now.num]) {
				if(au != now.parent) que.push({au, now.num, 1});
			}
		}
		//既に訪問済みの場所であれば、自分と親の情報を更新
		else{
			//葉判定
			if(now.num != 0 && g[now.num].size() == 1) ans[now.num] = {leaf_cnt, leaf_cnt}, leaf_cnt++;
			//子の情報から親の情報を更新
			chmin(ans[now.parent].first, ans[now.num].first);
			chmax(ans[now.parent].second, ans[now.num].second);
		}
	}
	for(auto au : ans) cout << au.first + 1 << " " << au.second + 1 << endl;
}