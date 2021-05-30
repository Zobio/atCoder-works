#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, k;
	cin >> n >> k;
	deque<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	int num = 0;
	while(a.size()) {
		for(int i = 0; i < k && a.size(); i++) {
			num++;
			if(a.size() >= 2) {a.pop_back(); continue;}
			if(a.back() / 2 > a.front() && a.back() / 2 > a[1]) {
				a.pop_back();
			}else{
				a.pop_front();
			}
		}
		int tmp = 0;
		while(a.back() / 2 < a[tmp]) tmp++;
		for(int j = 0; j < tmp; j++) a.pop_back();
		cnt += 1;
	}
	cout << cnt << " " << num << endl;
}