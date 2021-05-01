#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	string S;
    cin >> S;
    deque<char> q;
    bool rev = false;
	DWORD start = GetTickCount();
	for(char c : S){
        if(c == 'R') rev ^= 1;
        else if(rev) q.push_front(c);
        else q.push_back(c);
    }
	DWORD end = GetTickCount();
	std::cout << "duration = " << (double)(end - start) << "\n";
}