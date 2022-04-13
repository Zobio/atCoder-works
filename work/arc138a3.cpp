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

const ll MAX_N = 801010;
ll n;
vll dat(2 * MAX_N - 1); //セグメント木を持つグローバル配列

void init(int n_) {
	//簡単のため、要素数を2のべき乗に
	n = 1;
	while(n < n_) n *= 2;
	//全ての値をINFに
	rep(i, 2 * n - 1) dat[i] = INF;
}

//k番目の値(0-indexed)をaに変更
void update(ll k, ll a) {
	//葉の節点
	k += n - 1;
	dat[k] = a;
	//登りながら更新
	while(k) {
		k = (k - 1) / 2; //(∵0-indexed)
		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); //1個下の階層の2つの値のminをとる
	}
}

//[a, b)の最小値を求める
//後ろのほうの引数は、計算の簡単のための引数。
//kは節点の番号、l,rはその節点が[l, r)に対応づいていることを表す。
//従って、外からはquery(a, b, 0, 0, n)として呼ぶ。
//(kは配列datに対応する番号)
ll query(ll a, ll b, ll k, ll l, ll r) {
	//[a, b)と[l, r)が交差しなければ、INF
	if(r <= a || b <= l) return INF;

	//[a, b)が[l, r)を完全に含んでいれば、この節点の値
	if(a == l && b == r) return dat[k];
	else{
		ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
}

int main() {
	ll N, K; cin >> N >> K;
	vll a(N); rep(i, N) cin >> a[i];
	ll mi = INF; rep(i, K) chmin(mi, a[i]);
	init(K);
	rep(i, K) update(i, a[i]);
	ll ans = INF;
	for(ll i = K; i < N; i++) {
		if(a[i] <= mi) continue;
		ll l = 0, r = K;
		while(r - l > 1) {
			ll mid = (l + r) / 2;
			if(query(l, mid, 0, 0, K) < a[i]) r = mid;
			else l = mid;
		}
		chmin(ans, i - l);
	}
	cout << (ans == INF ? -1 : ans) << endl;
}