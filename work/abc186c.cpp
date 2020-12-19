#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nCopy = n;
	int k8 = 0, k10 = 0;
	while(nCopy >= 10) {
		nCopy /= 10;
		k10++;
	}
	nCopy = n;
	while(nCopy >= 8) {
		nCopy /= 8;
		k8++;
	}
	
}