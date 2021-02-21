#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(a != b) {
		if(a > b) cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
	}else{
		if (c) cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
	}
}