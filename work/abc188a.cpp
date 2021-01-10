#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if(n > m){
		if(n >= m + 3)
		cout << "No" << endl;
		else
		cout << "Yes" << endl;
	}else{
		if(n + 3 <= m)
		cout << "No" << endl;
		else
		cout << "Yes" << endl;
	}
}