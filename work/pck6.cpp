#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define INF (1ll << 60)

template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T& a, const T& b) {if (b < a) {a = b; return 1;} return 0;}

int main() {
	ll n, t; cin >> n >> t;
	vll a(n); rep(i, n) cin >> a[i];
	ll cur = 0; //時間
	ll dead = 0, dcnt = 0; //dead == 2ダメ dcntは加算されない回数
	rep(i, n) {
		cur += t;
		if(cur <= a[i]) cur = a[i], dead = 0; //間に合った
		else{
			dead++; dcnt++;
			if(dead == 2) {cout << i + 1 - dcnt << endl; return 0;}
		}
	}
	cout << n - dcnt << endl;
}