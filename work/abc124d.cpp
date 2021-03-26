#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n, k;
	string s;
	cin >> n >> k >> s;
	ll cnt0 = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			cnt0++;
		}
	}
	while(k > 0 && cnt0 > 0) {
		ll top = 0, now = 0;
		int place = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == '0') {
				now++;
			}else{
				if(top < now){
					top = now;
					place = i;
					if(place != 0) if(s[place - 1] == '0') place--;
				}
				now = 0;
			}
		}
		if(top < now) {
					top = now;
					place = s.length() - 1;
					if(place != 0) if(s[place - 1] == '0') place--;
		}
		while(s[place] == '0') {
			if(place < 0)break;
			s[place] = '1';
			place--;
			cnt0--;
		}
		k--;
		cout << s << endl;
	}
	ll top = 0, now = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			now++;
		}else{
			if(top < now)
				top = now;
			now = 0;
		}
	}
	if (top < now)
		top = now;
	cout << top << endl;
	cout << s << endl;
}