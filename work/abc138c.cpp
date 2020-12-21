#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<double, vector<double>, greater<double>> v;
	double tmp, tmp2;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		v.push(tmp);
	}
	for(int i = 0; i < n - 1; i++) {
		tmp = v.top();
		v.pop();
		tmp2 = v.top();
		v.pop();
		v.push((tmp + tmp2) / 2.0);
	}
	cout << fixed << setprecision(5) << v.top() << endl;
}