#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> bla;
	vector<ll> koma(n * 2 + 1, -1);
	for(int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		bla.push_back(make_pair(a, b));
		koma[b] = max(a, koma[b]);
	}
	sort(koma.begin(), koma.end());
	for(int i = n; i <= 2 * n; i++) {
		
	}
}