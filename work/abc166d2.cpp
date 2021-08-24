#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll x; cin >> x;
	for(ll i = -120; i <= 120; i++) for(ll j = -120; j <= 120; j++)
		if(i*i*i*i*i - j*j*j*j*j == x) {cout << i << " " << j << endl; return 0;}
}