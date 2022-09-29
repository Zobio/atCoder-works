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
#define rreep(i, a, b) for (long long i = a - 1; i >= b; i--)
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

int main() {
	ll n; cin >> n;
	vll a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vll cnt(5010);
	rep(i, n) cnt[a[i]]++;
	rep(i, n) cnt[b[i]]--;
	reps(i, 5000) if(cnt[i] != 0) {cout << "No" << endl; return 0;}
	rreep(i, n, 2) {
		if(a[i] == b[i]) continue;
		ll cor = -1;
		rep(j, i) if(a[j] == b[i]) cor = j;
		while(cor != i) {
			if(i - cor >= 2) {
				ll a0 = a[cor], a1 = a[cor + 1], a2 = a[cor + 2];
				a[cor] = a1; a[cor + 1] = a2; a[cor + 2] = a0;
				cor += 2;
			}else{
				ll a0 = a[cor - 1], a1 = a[cor], a2 = a[cor + 1];
				a[cor - 1] = a1; a[cor] = a2; a[cor + 1] = a0;
				cor--;
			}
		}
	}
	bool flag = false;
	rep(i, 3) {
		cout << endl << endl;
		arrcout(a);
		flag |= a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
		ll a0 = a[0], a1 = a[1], a2 = a[2];
		a[0] = a1; a[1] = a2; a[2] = a0;
	}
	cout << (flag ? "Yes" : "No") << endl;
}