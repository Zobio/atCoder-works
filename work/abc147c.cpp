#include <bits/stdc++.h>
using namespace std;

int solve(int base, vector<vector<int>> a, int ans, int n);

int main()
{
	int n;
	cin >> n;
	cout << n << endl;
	vector<vector<int>> a(20, vector<int>(20, -1));
	int tmp, tmp2;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		for(int j = 0; j < tmp; j++) {
			cin >> tmp2;
			cin >> a[i][tmp2 - 1];
		}
	}
	int base = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != -1)
			cout << i << " " << j << " " << a[i][j] << endl;
		}
	}
	for(;base <= pow(2, n); base++) {
		ans = solve(base, a, ans, n);
	}
	cout << n - ans << endl;
}

int solve(int base, vector<vector<int>> a, int ans, int n) {
	int want, count = 0;
	vector<bool> liar(n, false);
	for(int i = 0; i < n; i++) {
		want = (i >> i) % 2;
		for(int j = 0; j < n; j++) {
			if(a[j][i] != want && a[j][i] != -1){
				liar[j] = true;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(liar[i])
		count++;
	}
	cout << static_cast<bitset<15>>(base) << " " << count << endl;
	if(count < ans)
	return count;
	else
	return ans;
	cout << "okashii" << endl;
	return ans;
}