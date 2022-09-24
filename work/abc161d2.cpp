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

ll increment(ll cur) {
	string s = to_string(cur);
	ll digit = s.size();
	if(digit == 1) return cur + 1;
	ll flag_9 = true;
	rep(i, digit) flag_9 &= s[i] == '9';
	if(flag_9) return cur + 1;

	if(s[digit - 2] - 1 == s.back()) return cur + 1;

	if(s[digit - 2] != '9') {
		if(s[digit - 2] == s.back()) return cur + 1;
		else {
			if(digit == 2) return cur + 9;
			else if(!s[digit - 3])
		}
	}
	
	//...99パターンのみ残っている
	ll p = 0;
	rrep(i, digit) if(s[i] != '9') {p = i + 1; break;}
	if(p == 0) return mpow(10ll, digit, INF); //9999...999
	else if(p == 1) {
		string ret; ret += s.front() + 1;
		rep(i, digit - 1) ret += s.front(); //89999 --> 98888
		return stoll(ret);
	}
	else{
		string ret = s.substr(0, p - 1);
		ret += s[p - 1] + 1;
		rep(i, digit - p) ret += s[p - 1]; //678999 --> 325444
		return stoll(ret);
	}
}

int main() {
	ll n; cin >> n;
	ll ans = 0;
	rep(i, n) {
		ans = increment(ans);
		cout << ans << endl;
	}
	cout << ans << endl;
}