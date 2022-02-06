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
    int N;
    long long L;
    cin >> N >> L;
    vector<long long> a(N), s(N+1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    vector<int> pole({0, N-1});
    for (int i = 1; i < N-1; ++i) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) pole.push_back(i);
        if (a[i] < a[i-1] && a[i] < a[i+1]) pole.push_back(i);
    }
    sort(pole.begin(), pole.end());
	arrcout(pole);
    long long res = 0;
    for (int i = 0; i+1 < pole.size(); ++i) {
        int left = pole[i], right = pole[i+1] + 1;
		if(chmax(res, L * (right - left) - (s[right] - s[left]))) cout << L * (right - left) << " " << s[right] - s[left] << endl;
	}
    cout << res << endl;
}