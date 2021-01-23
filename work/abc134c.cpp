#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int first = 0, second = 0;
	bool doubleFirst = false;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(first < a[i]) {
			first = a[i];
		}
	}
	int fCnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == first)fCnt++;
	}
	if(fCnt > 1) doubleFirst = true;
	if(doubleFirst){
		for(int i = 0; i < n; i++) {
			cout << first << endl;
		}
	}else{
		for(int i = 0; i < n; i++) {
			if(second < a[i] && a[i] != first) {
				second = a[i];
			}
		}
		for(int i = 0; i < n; i++) {
			if(a[i] != first) {
				cout << first << endl;
			}else{
				cout << second << endl;
			}
		}
	}
}