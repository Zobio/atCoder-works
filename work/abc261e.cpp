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
#define mint modint998244353
#define INF (1LL << 60)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll bitcount(ll num) {
	ll ret = 0;
	while(num) ret++, num >>= 1;
	return ret;
}

int main() {
	/*
	操作の種類は、
	-, and, or, !and, !or
	の5種類。それを番号で管理してそれぞれの遷移を記録しておくことでO(NlogN)
	*/
	ll n, c; cin >> n >> c;
	ll b = 32; //max bit
	vpll a(n); rep(i, n) cin >> a[i].first >> a[i].second;
	vpll ch(b); //-, and, or, nand(-1), nor(-2), not(-3)
	rep(i, n) {
		rep(j, b) {
			ch[j].second = !!(a[i].second & 1ll << j); //0 or 1
			if(a[i].first == 3) {
				if(ch[j].first) ch[j].first *= -1;
				else if(ch[j].second) ch[j].first = -3; //not
			}
			else if(a[i].second == 1 && ch[j].second == 1);
			else if(a[i].second == 2 && ch[j].second == 0);
			else if(a[i].second == 1 && )
			else ch[j].first = a[i].first;

			if(abs(ch[j].first) == 1) { //and nand
				ll tmp = ch[j].second & 1ll << j;
				rep(k, b) if(k != j) tmp |= 1 << k;
				c &= tmp;
			}
			else if(abs(ch[j].first) == 2) { //or nor
				c |= ch[j].first & 1ll << j;
			}
			
			if(ch[j].first < 0) { // not
				ll bb = c & 1ll << j;
				if(bb) c &= ~(1ll << j);
				else c |= 1ll << j;
			}
		}
		rep(j, 5) cout << ch[j].first << " " << ch[j].second << endl;
		cout << c << endl;
	}
}