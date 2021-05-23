#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<vector<int>> pl(200);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ansbit = -1;
	int ansnum = -1;
	for(int bits = 0; bits < (int)pow(2, min(8, n)); bits++) {
		ll now = 0;
		for(int i = 0; i < min(8, n); i++) {
			if((bits >> i) & 1)
				now += a[i];
		}
		now %= 200;
		if(pl[now].size()) {
			ansbit = bits;
			ansnum = now;
			break;
		}
		for(int i = 0; i < min(8, n); i++){
			if ((bits >> i) & 1)
				pl[now].push_back(i);
		}
	}
	if(ansbit == -1) cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		cout << pl[ansnum].size() << " ";
		for(int i = 0; i < pl[ansnum].size(); i++) {
			cout << pl[ansnum][i] + 1 << " ";
		}
		cout << endl;
		int cnt = 0;
		for(int i = 0; i < min(8, n); i++) {
			if ((ansbit >> i) & 1) {
				cnt++;
			}
		}
		cout << cnt << " ";
		for(int i = 0; i < min(8, n); i++) {
			if ((ansbit >> i) & 1) {
				cout << i + 1 << " ";
			}
		}
		cout << endl;
	}
}