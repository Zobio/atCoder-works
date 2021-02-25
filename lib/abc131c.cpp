#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	// a<bのときa % b == aなので結局gcd(b, a)に帰結する。
	if (a % b == 0) {
		return b;
	}else{
		return gcd(b, a % b);
	}
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	long long a, b, c, d, ansC = 0, ansD = 0, ansCD = 0;
	cin >> a >> b >> c >> d;
	long long start = 0;
	start += c * (a / c);
	while(start < a) start += c;
	if(start <= b) {
	ansC = (b - start) / c + 1;
	if(start == b && b % c != 0) ansC--;
	}
	start = 0;
	start += d * (a / d);
	while(start < a) start += d;
	if(start <= b) {
	ansD = (b - start) / d + 1;
	if(start == b && b % d != 0) ansD--;
	}
	start = 0;
	start += lcm(c, d) * (a / lcm(c, d));
	while(start < a) start += lcm(c, d);
	if(start <= b) {
	ansCD = (b - start) / lcm(c, d) + 1;
	if(start == b && b % lcm(c, d) != 0) ansCD--;
	}
	cout << b - a + 1 - (ansC + ansD - ansCD) << endl;
}