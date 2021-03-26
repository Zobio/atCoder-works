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
	ll cnt = 0;
	if(s[0] == '0') situ.push_back(0);
	for(int i = 0; i < n; i++) {
		if(s[i] == (char)now + '0') {
			cnt++;
		}else{
			situ.push_back(cnt);
			now = (now == 0 ? 1 : 0);
			cnt = 1;
		}
	}
	if(cnt != 0) situ.push_back(cnt);
	if (s.back() == '0') situ.push_back(0);
	vector<int> sums((int)situ.size() + 1, 0);
	for(int i = 0; i < situ.size(); i++) {
		sums[i + 1] = situ[i] + sums[i];
	}
	int ans = 0;
	for(int left = 0; left < sums.size(); left += 2) {
		int right = left + k * 2 + 1;
		if (right >= sums.size()) right = (int)sums.size() - 1;
		ans = max(ans, sums[right] - sums[left]);
	}
	cout << ans << endl;
}