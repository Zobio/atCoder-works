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
#define arrcout(a) for(size_t i = 0; i < N; i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

long long N;
vll A(1ll << 20), B(1ll << 20);
string S;

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		if (S[i - 1] == 'o') { A[i] = i; B[i] = B[i - 1]; }
		if (S[i - 1] == 'x') { A[i] = A[i - 1]; B[i] = i; }
	}

	long long Answer = 0;
	arrcout(A); arrcout(B);
	for (int i = 1; i <= N; i++) {
		Answer += 1LL * min(A[i], B[i]);
		cout << i << " " << min(A[i], B[i]) << endl;
	}
	cout << Answer << endl;
	return 0;
}