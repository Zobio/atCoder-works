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
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n; vll a(n); rep(i, n) cin >> a[i];
	vll len(n + 1); //len[i]...地点iにおける"連続する"白または黒の碁石の個数
	len[1] = 1; //初期化
	reps(i, n - 1) {
		if(a[i] == a[i - 1]) len[i + 1] = len[i] + 1; //同じ色は長さが1増えるだけ
		else if(i & 1/*偶数*/) {
			len[i + 1] = len[i] +  len[i - len[i]] + 1; //i-len[i]番目までの長さ(今と同じ色)と、(旧)len[i](今と違う色)の長さが結合される
		}else{
			len[i + 1] = 1; //色が変化し、長さは1になる
		}
	}
	ll ans = 0;
	for(ll i = n; i > 0; i -= len[i]) if(a[i - 1] == 0) ans += len[i];
	//それぞれの区間で、先頭が0(白)だったらそこの区間は全て白なので足す
	cout << ans << endl;
}