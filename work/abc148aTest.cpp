#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> num = {1, 2, 3};
	num.erase(remove(num.begin(), num.end(), 2), num.end());
	for(int i = 0; i < num.size(); i++) {
		cout << num[i] << endl;
	}
}