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


class ProcessingTime {

public:
    ProcessingTime(const std::string &name = "Process", bool start = true) :
            m_name(name),
            m_isActive(start) {
        if (start) {
            this->restart();
        }
    }

    ~ProcessingTime() {
        this->stop();
    }

    ///<summary>
    ///計測のリスタート
    ///</summary>
    void restart() &{
        m_start = std::chrono::system_clock::now();
        m_isActive = true;
    }

    ///<summary>
    ///計測を終了し出力
    ///</summary>
    void stop() &{
        if (!m_isActive)
            return;
        const auto end = std::chrono::system_clock::now();
        const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start).count();
        std::cout << elapsed << "ms" << std::endl;

        m_isActive = false;
    }

private:

    std::string m_name;
    std::chrono::system_clock::time_point m_start;
    bool m_isActive;

};

struct HashPair {

    static size_t m_hash_pair_random;

    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {

        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= m_hash_pair_random + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

size_t HashPair::m_hash_pair_random = (size_t) random_device()();

int main() { //unordered_mapの実装(TLE)
	ll n; cin >> n;
	vpll cor(n);
	unordered_map<pair<ll, ll>, ll, HashPair> mp;
	rep(i, n) {
		ll x, y; cin >> x >> y;
		cor[i] = {x, y}; mp[{x, y}]++;
	}
	sort(all(cor));
	ll ans = 0;
	rep(i, n) for(ll j = i + 1; j < n; j++) {
		ll a1 = cor[i].first, a2 = cor[i].second, b1 = cor[j].first, b2 = cor[j].second;
		ll dx = a1 - b1, dy = a2 - b2;
		if(mp[{a1 + dy, a2 - dx}] && mp[{b1 + dy, b2 - dx}]) chmax(ans, dx * dx + dy * dy);
		else if(mp[{a1 - dy, a2 + dx}] && mp[{b1 - dy, b2 + dx}]) chmax(ans, dx * dx + dy * dy);
	}
	cout << ans << endl;
}
