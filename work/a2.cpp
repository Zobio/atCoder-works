#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a;
	cin >> n >> a;
	a -= 1;
	vector<char> s(n);
	int sharpCnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		if (s[i] == '#') {
			sharpCnt++;
		}
	}
	vector<int> sPlace(sharpCnt);
	vector<bool> yet(sharpCnt, true);
	int tmp = 0;
	int first = 0;
	int spot = 0;
	bool done = false;
	bool right = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == '#')
		{
			sPlace[tmp] = i;
			tmp++;
			if(sPlace[tmp] > a && !done) {
				spot = tmp;
				first = i; //地点
				done = true;
				yet[tmp] = false;
			}
		}
	}
	if(!done) {
		first = sPlace[sharpCnt - 1];
		right = false;
		spot = sharpCnt - 1;
		yet[sharpCnt - 1] = false;
	}
	int all = sharpCnt;
	long long cnt = 0;
	cnt += abs(first - a); //spotは要素の位置
	int base = 1;
	bool aa = true;
	if(done) aa = false;
	bool up = true;
	bool go = false;
	int old = sharpCnt;
	while(sharpCnt > 0) {
		if(aa) {
			if(spot + base < all) {
			cnt += abs(sPlace[spot] - sPlace[spot + base]);
			spot += base;
			base++;
			sharpCnt--;
			}else{
				up = true;
				go = true;
				old = sharpCnt;
				sharpCnt = 0;
			}
		}else{
			if (spot - base >= 0) {
				cnt += abs(sPlace[spot] - sPlace[spot - base]);
				spot -= base;
				base++;
				sharpCnt--;
			}else{
				up = false;
				go = true;
				old = sharpCnt;
				sharpCnt = 0;
			}
		}
		aa = !aa;
	}
	if(go && up) {
		for(int i = spot; i < old; i++) {
			cnt += (n - sPlace[i]) * 2 + 2;
		}
	}
	else if(go && !up) {
		for(int i = spot; i >= 0; i--) {
			cnt += sPlace[i] * 2 + 2;
		}
	}
	cout << cnt << endl;
}