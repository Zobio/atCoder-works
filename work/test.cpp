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

ll n, m, k;
vector<vector<pair<ld, ld>>> cor;
vvpll g;
vector<vector<vector<ld>>> dist;

int main() {
    setcout(15);
    ll hash = 21;

    cin >> n >> m >> k; //n角形、m枠
	pll st, en; cin >> st.first >> st.second >> en.first >> en.second;
    st.first--; en.first--;
	ld angle = PI * (n - 2) / n;
	cor.resize(m, vector<pair<ld, ld>>(n)); //座標
	rep(i, m) rep(j, n) {
		cor[i][j] = {polar<ld>(i + 1, angle * j).real(), polar<ld>(i + 1, angle * j).imag()};
	}
    ld sum = 0;
    ll a1, a2, b1, b2; a1 = st.first; a2 = st.second;
    while(1) {
        cin >> b1 >> b2; b1--;
        cout << cor[a1][a2].first << " " << cor[a1][a2].second << "  " << cor[b1][b2].first << " " << cor[b1][b2].second << endl;
        ld d = sqrtl((cor[a1][a2].first - cor[b1][b2].first) * (cor[a1][a2].first - cor[b1][b2].first) + (cor[a1][a2].second - cor[b1][b2].second) * (cor[a1][a2].second - cor[b1][b2].second));
        cout << "now : " << d << endl;
        sum += d;
        cout << "sum : " << sum << endl;
        a1 = b1; a2 = b2;
    }
}