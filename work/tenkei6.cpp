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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	vvll nxt(n + 10, vll(26, n)); //nxt[i][j] ... i番目の文字より右にある文字jの中で1番左にあるもののインデックス(nはnot found)
	rrep(i, n) { //nxtを前計算
		rep(j, 26) {
			if(s[i] == 'a' + j) nxt[i][j] = i;
			else nxt[i][j] = nxt[i + 1][j];
		}
	}
	string ans;
	ll cur = 0;
	reps(i, k) rep(j, 26) { //1文字ずつ決めていく(O(K * 26))
		ll nxtPos = nxt.at(cur).at(j);
		ll maxLen = n - nxtPos - 1; //0-indexedなので-1
		if(maxLen < k - i) continue; //文字数が足りなければダメ
		ans += 'a' + j;
		cur = nxtPos + 1;
		break;
	}
	cout << ans << endl;
}