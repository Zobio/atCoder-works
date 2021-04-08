#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	vector<int> a(5);
	int k;
	for(int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	cin >> k;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(i == j || a[i] < a[j]) continue;
			if(a[i] - a[j] > k) {
				cout << ":(" << endl;
				return 0;
			}
		}
	}
	cout << "Yay!" << endl;
}