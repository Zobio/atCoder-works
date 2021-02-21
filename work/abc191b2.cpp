#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	list<int> a;
	int tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	a.remove(x);
	for(auto q : a) {
		cout << q << " ";
	}
	cout << endl;
}