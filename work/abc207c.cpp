#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

bool judge(int a, int b, int c, int d) {
	if(a > c && b < d) return true;
	if(a < d && b >= d) return true;
	if(a <= c && b > d) return true;
	if(a < d && b > c) return true;
	else return false;
}

int main() {
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> num(n);
	for(int i = 0; i < n; i++) {
		cin >> num[i].second >> num[i].first.first >> num[i].first.second;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(judge(num[i].first.first, num[i].first.second, num[j].first.first, num[j].first.second)) {
				ans++; continue;
			}
			if(num[i].first.second == num[j].first.first) {
				if((num[i].second == 1 || num[i].second == 3) && (num[j].second == 1 || num[j].second == 2)) {
					ans++; continue;
				}
			}
			if(num[i].first.first == num[j].first.second) {
				if((num[i].second == 1 || num[i].second == 2) && (num[j].second == 1 || num[j].second == 3)) {
					ans++; continue;
				}
			}
		}
	}
	cout << ans << endl;
}