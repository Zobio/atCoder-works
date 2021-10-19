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
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a)                         \
	for (size_t i = 0; i < a.size(); i++)  \
		cout << (i ? " " : "") << a.at(i); \
	cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template <class T>
bool chmax(T &a, const T &b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return 1;
	}
	return 0;
}

ll gcd(ll a, ll b) {
	// a<bのときa % b == aなので結局gcd(b, a)に帰結する。
	if (a % b == 0) {
		return b;
	}else{
		return gcd(b, a % b);
	}
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << "GCD: " << gcd(n, m) << endl;
}