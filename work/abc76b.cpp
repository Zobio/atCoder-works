#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long long now = 1;
	for(int i = 0; i < n; i++) {
		if(now + k > now * 2) {
			now *= 2;
		}else{
			now += k;
		}
	}
	cout << now << endl;
}