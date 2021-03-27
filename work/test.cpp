#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int n, m;
vector<int> a;

void dfs(int id, int pre) {
	cout << "id: " << id << endl;
	if(id == n) {
		for(int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}else{
		for(int i = pre; i <= m; i++) {
			a[id] = i;
			dfs(id + 1, i);
		}
	}
}

int main() {
	cin >> n >> m;
	a.resize(n);
	dfs(0, 0);
}