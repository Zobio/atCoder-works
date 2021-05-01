#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> like(m, true);
	for(int i = 0; i < n; i++) {
		int k; cin >> k;
		vector<int> lst;
		for(int j = 0; j < k; j++) {
			int a; cin >> a; a--; lst.push_back(a);
		}
		for(int j = 0; j < m; j++) {
			if(!binary_search(lst.begin(), lst.end(), j)) cout << j << endl,like[j] = false;
		}cout << endl;
	}
	int cnt = 0;
	for(int i = 0; i < m; i++) {
		if(like[i]) cnt++;
	}
	cout << cnt << endl;
}