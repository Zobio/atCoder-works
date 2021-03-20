#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n;
	cin >> n;
	ll ans = 0;
	ll base = 0;
	if(n <= 99) {
		base = 1;
		for(int i = 0; i < 9; i++) {
			if(n >= base * 10 + base) ans++;
			base++;
		}
	}
	else if(n <= 9999) {
		ans += 9;
		base = 10;
		for(int i = 0; i < 99; i++) {
			if(n >= base * 100 + base) ans++;
			base++;
		}
	}
	else if(n <= 999999) {
		ans += 99;
		base = 100;
		for(int i = 0; i < 999; i++) {
			if(n >= base * 1000 + base) ans++;
			base++;
		}
	}
	else if(n <= 99999999) {
		ans += 999;
		base = 1000;
		for(int i = 0; i < 9999; i++) {
			if(n >= base * 10000 + base) ans++;
			base++;
		}
	}
	else if(n <= 9999999999) {
		ans += 9999;
		base = 10000;
		for(int i = 0; i < 99999; i++) {
			if(n >= base * 100000 + base) ans++;
			base++;
		}
	}
	else if(n <= 999999999999) {
		ans += 99999;
		base = 100000;
		for(int i = 0; i < 999999; i++) {
			if(n >= base * 1000000 + base) ans++;
			base++;
		}
	}
	else if(n <= 99999999999999) {
		ans += 999999;
		base = 1000000;
		for(int i = 0; i < 9999999; i++) {
			if(n >= base * 10000000 + base) ans++;
			base++;
		}
	}
	cout << ans << endl;
}