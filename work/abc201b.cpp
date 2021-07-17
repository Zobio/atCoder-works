#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007 #include<bits / stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<pair<int, string>> pairs(n);
	for(int i = 0; i < n; i++) {
		cin >> pairs[i].second >> pairs[i].first;
	}
	sort(pairs.rbegin(), pairs.rend());
	cout << pairs[1].second << endl;
}