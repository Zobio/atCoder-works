#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007


ll ggcd(ll num)
{
    if (num % 2 == 0) return 2; // 偶数はあらかじめ除く

    for (ll i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return i;
        }
    }

    // 素数である
    return -1; 
}

int main() {
	ll n, p;
	cin >> n >> p;
	ll ans = 1;
	vector<ll> ele;
	while(p > 1) {
		if(ggcd(p) == -1) {
			ele.push_back(p);
			break;
		}
		ele.push_back(ggcd(p));
		p /= ggcd(p);
	}
	map<ll, pair<ll, ll>> sum;
	for(auto e : ele) sum[e].first++, sum[e].second = e;
	for(auto s = sum.begin(); s != sum.end(); s++) {
		if(s -> second.second == 1 || s -> second.first < n) continue;
		if((s -> second.first) >= n) for(int i = 0; i < (s -> second.first) / n; i++) ans *= (s -> second.second);
	}
	cout << ans << endl;
}