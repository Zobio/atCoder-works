#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(to_string(i).length() % 2)ans++;
	}
	cout << ans << endl;
}