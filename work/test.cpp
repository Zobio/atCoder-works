#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v(10);
	v.assign(15, 100);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
