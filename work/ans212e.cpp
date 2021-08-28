#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int mod = 998244353;
class mint
{
	long long x;

public:
	mint(long long x = 0) : x((x % mod + mod) % mod) {}
	mint operator-() const
	{
		return mint(-x);
	}
	mint &operator+=(const mint &a)
	{
		if ((x += a.x) >= mod)
			x -= mod;
		return *this;
	}
	mint &operator-=(const mint &a)
	{
		if ((x += mod - a.x) >= mod)
			x -= mod;
		return *this;
	}
	mint &operator*=(const mint &a)
	{
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint &a) const
	{
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint &a) const
	{
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint &a) const
	{
		mint res(*this);
		return res *= a;
	}
	mint pow(ll t) const
	{
		if (!t)
			return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1)
			a *= *this;
		return a;
	}
	// for prime mod
	mint inv() const
	{
		return pow(mod - 2);
	}
	mint &operator/=(const mint &a)
	{
		return (*this) *= a.inv();
	}
	mint operator/(const mint &a) const
	{
		mint res(*this);
		return res /= a;
	}

	friend ostream &operator<<(ostream &os, const mint &m)
	{
		os << m.x;
		return os;
	}
};

int N, M, K;
vector<int> E[5050];
mint dp[5010][5010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M >> K;
    rep(i, 0, M) {
        int U, V; cin >> U >> V;
        U--; V--;
        E[U].push_back(V);
        E[V].push_back(U);
    }
    
    dp[0][0] = 1;
    rep(day, 0, K) {
        mint tot = 0;
        rep(lst, 0, N) tot += dp[day][lst];
        rep(nxt, 0, N) {
            dp[day + 1][nxt] = tot - dp[day][nxt];
            fore(lst, E[nxt]) dp[day + 1][nxt] -= dp[day][lst];
			cout << day + 1 << " " << nxt << " : " << dp[day + 1][nxt] << endl;
        }
    }

    cout << dp[K][0] << endl;
}