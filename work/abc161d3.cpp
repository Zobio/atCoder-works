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

template<typename T>
T mpow(T a, T n, T m) {
	/*a^n % mを返す
	(例)
	pow(2, 10, 1000) --> 24
	計算量はlog(n)
	*/
	T ret = 1;
	while(n > 0) {
		if (n & 1) ret = ret * a % m;
		a = a % m * a % m;
		n >>= 1;
	}
	return ret;
}

string increment(string from) {
	ll digit = from.size();
	for(ll i = digit - 1; i > 0; i--) {
		ll cur = from[i] - '0';
		ll nxt = from[i - 1] - '0';

		if(cur < 9 && abs(cur + 1 - nxt) <= 1) { //繰り上がりしてOK(curが+1されても差が1以内)
			from[i]++;
			reep(j, i + 1, digit) from[j] = max('0', (char)(from[j - 1] - 1)); //765432100000...
			return from;
		}
	}
	
	//最後まで繰り上がりできなかった
	ll top = from.front() - '0';
	if(top < 9) {
		from.front()++;
		reep(i, 1, digit) from[i] = max('0', (char)(from[i - 1] - 1)); // 765432100000...
		return from;
	}
	else return to_string(mpow(10ll, digit, INF));


}

int main() {
	ll n; cin >> n;
	string ans = "1";
	rep(i, n - 1) {
		ans = increment(ans);
	}
	cout << ans << endl;
}