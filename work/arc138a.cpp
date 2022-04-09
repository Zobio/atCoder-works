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
#define SIZE 128 * 1024
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

struct segtree
{
	ll seg[SIZE*2];
	ll n,mum;
	
	void init()
	{
		mum = 1;
		while(mum < n) mum *= 2;
		memset(seg, -1010101010, sizeof(seg));
	}
	void updata(ll k,ll x)
	{
		k += mum - 1;
		seg[k] = x;
		while(k > 0)
		{
			k = (k - 1) / 2;
			seg[k] = max(seg[k * 2 + 1], seg[k * 2 + 2]);
		}
	}
	ll maximum(ll a,ll b,ll k,ll l,ll r)
	{ // [a,b)の最小値を取得する // k:現在見ているノードの位置  [l,r):dat[k]が表している区間
		if(b <= l || r <= a) return 0;
		if(a <= l && r <= b) return seg[k];
		else
		{
			ll v1=maximum(a, b, k * 2 + 1, l, (l + r) / 2);
			ll v2=maximum(a, b, k * 2 + 2, (l + r) / 2, r);
			return max(v1, v2);
		}
	}
	ll maximum(ll a)
	{
		return maximum(a, mum, 0, 0, mum);
	}
};

template<typename V>
void shrink_coordinates(V& a) {
	/*
	座標圧縮を行う関数
	(例)
	{6, 9, 9, 2, 100} -->  {1, 2, 2, 0, 3}
	*/
	V b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	V res(a.size());
	for(long long i = 0; i < a.size(); i++) {
		res.at(i) = lower_bound(b.begin(), b.end(), a.at(i)) - b.begin();
	}
	a = res;
}

int main() {
	ll n, k; cin >> n >> k;
	vll a(n); rep(i, n) cin >> a[i];
	shrink_coordinates(a);
	ll mi = INF; rep(i, k) chmin(mi, a[i]);
	arrcout(a);
	segtree seg;
	seg.n = k; seg.init();
	ll mum = 1; while(mum < n) mum *= 2;
	rep(i, k) seg.updata(i, -a[i]);
	ll ans = INF;
	for(ll i = k; i < n; i++) {
		cout << "now: " << a[i] << endl;
		if(a[i] <= mi) continue;
		ll l = -1, r = k - 1;
		while(r - l > 1) {
			ll mid = (l + r) / 2;
			cout << seg.maximum(mid, r, 0, 0, k) << " " << -a[i] << endl;
			if(seg.maximum(mid, r, 0, 0, k) > -a[i]) l = mid;
			else r = mid;
			cout << l << " " << r << "  : " << seg.maximum(l, r, 0, 0, k) << endl;
		}
		cout << i << " " << r << "  " << i - r << endl;
		chmin(ans, i - r);
	}
	cout << (ans == INF ? -1 : ans) << endl;
}