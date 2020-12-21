#include <bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<double, vector<double>, greater<double>> v;
	double tmp;
	for(int i = 0; i < 5; i++) {
		cin >> tmp;
		v.push(tmp);
	}
	while (!v.empty()){
		cout << v.top() << " ";
		v.pop();
	}
	cout << endl;
}