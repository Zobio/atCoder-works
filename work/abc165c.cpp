#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

ll ans = 0;
int n, m, q;
vector<int> lst;

void dfs() {
	
}

int main() {
	cin >> n >> m >> q;
	lst.resize(n);
	vector<vector<int>> num(q, vector<int>(4));
	for(int i = 0; i < q; i++) {
		cin >> num[i][0] >> num[i][1] >> num[i][2] >> num[i][3];
	}
}