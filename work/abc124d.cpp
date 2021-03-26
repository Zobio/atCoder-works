#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n, k;
	string s;
	cin >> n >> k >> s;
	bool fst1 = false;
	if(s[0] == '1') fst1 = true;
	int now = (int)fst1;
	vector<int> situ;
	ll cnt = 0; bool all0 = true, all1 = true;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') all0 = false;
		if(s[i] == '0') all1 = false;
		if(s[i] == (char)now + '0') {
			cnt++;
		}else{
			situ.push_back(cnt);
			now = (now == 0 ? 1 : 0);
			cnt = 1;
		}
	}
	if(all0) {
		cout << (k > 0 ? n : 0) << endl;
		return 0;
	}
	if(all1) {
		cout << n << endl;
		return 0;
	}
	if(cnt != 0) situ.push_back(cnt);
	ll top = 0, sum = 0; int place = 0, cnt0;
	if(fst1) cnt0 = situ.size() / 2;
	else if(situ.size() & 1) cnt0 = situ.size() / 2 + 1;
	else cnt0 = situ.size() / 2;
	bool fst1End = false;
	while(k > 0 && cnt0 > 0) {
		if(fst1) {
			if(situ.size() == 1) {
				cout << n << endl;
				return 0;
			}
			if(situ.size() == 2)
			top = situ[0] + situ[1]; place = 0; sum = top;
			for(int i = 0; i < situ.size() - 2; i+=2) {
				sum += situ[i] + situ[i + 1] + situ[i + 2];
				if(sum > top) top = sum, place = i;
				sum = 0;
			}
			sum = situ[place] + situ[place + 1] + situ[place + 2];
		}else{
			if(situ.size() == 1) {
				cout << n << endl;
				return 0;
			}
			if(!fst1End || situ.size() == 2)
			top = situ[0] + situ[1]; place = 0; sum = top;
			for(int i = 1; i < situ.size() - 2; i+=2) {
				sum += situ[i] + situ[i + 1] + situ[i + 2];
				if(sum > top) top = sum, place = i;
				sum = 0;
			}
			if(place) sum = situ[place] + situ[place + 1] + situ[place + 2];
		}
		if(!fst1 && place == 0) fst1End = true;
		vector<int> situCp;
		for(int i = 0; i < situ.size(); i++) {
			if(i == place) {
				situCp.push_back(sum);
			}
			else if(i < place || i > place + (!fst1 && place == 0 ? 1 : 2)) {
				situCp.push_back(situ[i]);
			}
		}
		situ = situCp;
		k--, cnt0--, sum = 0, top = 0;
	}
	top = 0;
	for(int i = ((fst1 || fst1End) ? 0 : 1); i < situ.size(); i+=2) {
		if(top < situ[i]) top = situ[i];
	}
	cout << top << endl;
}