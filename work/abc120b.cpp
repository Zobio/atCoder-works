#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	int cnt = 0;
	vector<int> lst;
	for(int i = 1;i <= max(a, b);i++) {
		if(a % i == 0 && b % i == 0) lst.push_back(i);
	}
	cout << lst[lst.size() - k] << endl;
}