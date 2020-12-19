#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> cnt(n);
	int tmp;
	for(int i = 0; i < q; i++) {
		cin >> tmp;
		cnt[tmp - 1]++;
	}
	for(int i = 0; i < n; i++) {
		if(q - cnt[i] < k) {
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
}