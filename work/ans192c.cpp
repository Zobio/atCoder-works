#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int k;
	cin >> s >> k;
	for(int i=0;i<k;i++){
		string t = s;
		sort(t.rbegin(),t.rend());
		sort(s.begin(),s.end());
		s = to_string(stoi(t)-stoi(s));
		cout << stoi(t) << " " << stoi(s) << endl;
	}
	cout << s << endl;
}