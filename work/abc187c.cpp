#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	list<string> w;
	string now;
	list<string>::iterator itr;
	for(int i = 0; i < n; i++) {
		cin >> now;
		if(now[0] == '!') {
			w.push_back(now);
			continue;
		}
		itr = find(w.begin(), w.end(), ("!" + now));
		if(itr != w.end()) {
			cout << now << endl;
			return 0;
		}
	}
	cout << "satisfiable" << endl;
}