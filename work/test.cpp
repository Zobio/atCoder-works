#include <bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bc;
	priority_queue<int> pq;
	pq.push(1);
	pq.push(1);
	pq.push(1);
	pq.push(3);
	pq.push(5);
	cout << "size: " << pq.size() << endl;
	int s = pq.size();
	for(int i = 0; i < s; i++) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	cout << "size: " << pq.size() << endl;
}