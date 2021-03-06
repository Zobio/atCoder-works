#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

string s;

int judge(char a, char b) {
	if(a == '0' && b == '0') return 0;
	else if(a == '0' || (a == '1' && (b == '0' || b == '1' || b == '2'))) return 1;
	else return 2;
}

int main() {
	cin >> s;
	char a = s[0], b = s[1], c = s[2], d = s[3];
	if((judge(a, b) == 0 || judge(a, b) == 2) && (judge(c, d) == 0 || judge(c, d) == 2)) {
		cout << "NA" << endl;
		return 0;
	}
	if(judge(a, b) == 1 && judge(c, d) == 1) {
		cout << "AMBIGUOUS" << endl;
	}
	else if(judge(a, b) == 1) {
		cout << "MMYY" << endl;
	}else{
		cout << "YYMM" << endl;
	}
}