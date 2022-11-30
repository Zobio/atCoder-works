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
#define reep(i, a, b) for(long long i = a; i < b; i++)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define dll deque<long long>
#define ddll deque<dque<long long>>
#define dddll deque<deque<deque<long long>>>
#define ddddll deque<deque<deque<deque<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template<typename VV>
void rotate_90(VV& a) {
	/*2次元グリッドを反時計回りに90°回転させる関数 (2回回せば逆さまになる)
	(例)
	000     011
	001 --> 000
	101     001
	注意 : 縦と横のサイズが同じでないとバグる
	*/
	size_t siz = a.size();
	VV b(siz);
	for(size_t i = 0; i < siz; i++) for(size_t j = 0; j < siz; j++) b[i].push_back(a[j][siz - i - 1]);
	a = b;
}

int main() {
	ll h, w; cin >> h >> w;
	vector<string> s(h), t(h);
	rep(i, h) cin >> s[i];
	rep(i, h) cin >> t[i];
	vector<string> a(w), b(w);
	rep(i, h) rep(j, w) a[j].push_back(s[i][j]);
	rep(i, h) rep(j, w) b[j].push_back(t[i][j]);
	map<string, ll> p, q;
	rep(i, w) p[a[i]]++, q[b[i]]++;
	bool flag = true;
	for(auto au : p) flag &= q.count(au.first) && q[au.first] == au.second;
	for(auto au : q) flag &= p.count(au.first) && p[au.first] == au.second;
	cout << (flag ? "Yes" : "No") << endl;
}