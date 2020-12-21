#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	list<double> v;
	double tmp, tmp2;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for(int i = 0; i < n - 1; i++) {
		v.sort();
		tmp = v.front();
		v.pop_front();
		tmp2 = v.front();
		v.pop_front();
		v.push_front((tmp + tmp2) / 2);
	}
	cout << fixed << setprecision(5) << v.front() << endl;
}