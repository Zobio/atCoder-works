#include <bits/stdc++.h>
#define MAX_ELEMENT 300000 //要変更
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout << max(0, b - a + 1) << endl;
}