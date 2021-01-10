#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr = 1;
	for(int i = 0; i < n; i++) arr *= 2;
	vector<long long> a(arr);
	long long tmp = 0;
	int top = 0;
	for(int i = 0; i < arr; i++) {
		cin >> a[i];
		if(tmp < a[i]) {
			top = i;
			tmp = a[i];
		}
	}
	bool mae = true;
	if(arr / 2 > top) mae = false;
	int second = 0;
	tmp = 0;
	if(mae) {
		for(int i = 0; i < arr / 2; i++) {
			if(tmp < a[i]) second = i, tmp = a[i];
		}
	}else{
		for(int i = arr / 2; i < arr; i++) {
			if(tmp < a[i]) second = i, tmp = a[i];
		}
	}
	cout << second  + 1 << endl;
}