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

int h,w;
vector<string> mp(110);
vvll f(110, vll(110));
int dfs(int x,int y) {
	if(f[x][y]) return f[x][y];
	int res = 0;
	if(x + 1 < h) if(mp[x+1][y] == '.') chmax(res,dfs(x + 1,y));
	if(y + 1 < w) if(mp[x][y+1] == '.') chmax(res,dfs(x,y + 1));
	return f[x][y] = res + 1;
}
int main() { //DFSによる解法
	cin >> h >> w;
	for(int i = 0;i < h;i++) cin >> mp[i];
	cout<< dfs(0, 0) << endl;
}