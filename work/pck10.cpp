#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define INF (1ll << 60)
#define all(a) (a).begin(), (a).end()

template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T& a, const T& b) {if (b < a) {a = b; return 1;} return 0;}

int main() {
	//グラフ問題に帰着できそう
	//fromは変えことができるがtoはムリ
	//移動コストをうまい事操作して辺をつなげてdijkstraできそう
	ll n, m, c; cin >> n >> m >> c;
	vll a(m), b(m), f(m);
	rep(i, m) cin >> a[i] >> b[i] >> f[i];

}