#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	try{
		cout << stoi(s) * 10 << endl;
	}catch(invalid_argument i) {
		cout << "invalid_argument!" << endl;
		cout << i.what() << endl;
	}
}
