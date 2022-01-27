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
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 100000LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll digit_sum(ll n) {
	ll ret = 0;
	for(auto a : to_string(n)) ret += a - '0';
	return ret;
}

int main() {
	ll n, k; cin >> n >> k;
	vll nxt(MOD, -1);
	rep(i, MOD) {
		nxt[i] = (i + digit_sum(i)) % MOD;
	}
	vll time_stamp(MOD, -1);
	ll cur = n, cnt = 0; //nからスタート(周期を測定)
	while(time_stamp[cur] == -1) {
		time_stamp[cur] = cnt;
		cur = nxt[cur];
		cnt++;
	}
	ll cycle = cnt - time_stamp[cur]; //サイクル数(2回目の番目(== cnt) - 1回目の番目(== time_stamp[cur]))
	if(k >= time_stamp[cur]) { //kがサイクルの初めの数であるtime_stamp[cur]以上であったらループに突入している→MODをとってKを小さく
		k = (k - time_stamp[cur]) % cycle + time_stamp[cur];
		/*
		Kを小さな数にする
		具体的には、time_stamp[cur]から周期が始まっていてそこから何回も回っているので、そこの部分をcycleでMODをとっている
		*/
	}
	ll ans = -1;
	rep(i, MOD) if(time_stamp[i] == k) ans = i;
	cout << ans << endl;
}