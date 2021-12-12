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

int main() {
	ll n, d, k; cin >> n >> d >> k;
	vpll e(n);
	rep(i, n) cin >> e[i].second >> e[i].first;
	sort(all(e)); rep(i, n) swap(e[i].first, e[i].second);
	ll ans = 0;
	for (ll bits = 0; bits < (1ll << n); bits++) {//bitsでi-1番目のイベントの後「移動するか」を管理
		vector<bool> join(n);
		ll cnt = 0, time = 0, eve = 0; bool at1 = true;
		rep(i, n) {
			if(i == 0) { //例外処理
				if(bits & (1ll << (n - i)))time += d + k * eve,	at1 = !at1; //移動
				else;//何もしない
			}
			else if(bits & (1ll << (n - i))) {//移動
				//cout << "IDOU: " << eve << " " << d + k * eve << " " << endl;
				//cout << (join[i - 1] ? e[i - 1].second + 1 : 0) + d + k * eve << endl;
				if(join[i - 1]) time = e[i - 1].second + d + k * eve;
				else time += d + k * eve;
				at1 = !at1;
				eve = 0;
			}
			
			if(at1 == (e[i].first == 1) && time <= e[i].second){ //イベント参加
				eve++; cnt++; join[i] = true; time = e[i].second + 1;
			}
			chmax(time, e[i].second);
			//cout << time << " " << (at1 ? 1 : 2) << " " << cnt << endl;
		}
		if(chmax(ans, cnt)) cout << bitset<12>(bits) << " ... " << cnt << endl;
	}
	cout << ans << endl;
}