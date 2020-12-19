#include <bits/stdc++.h>
using namespace std;

int main() {
	//priority_queueは配列のなかの一番大きい値を返すのが高速でできるため、forで毎回sortするなどの場合はこっちを使ったほうがいい。
	priority_queue<int> q;
	q.push(1);
	q.push(3);
	q.push(2);
	cout << q.top() << endl; //入れた要素の中で一番おおきい値が出力される。(3)
	q.pop();//一番大きい値を削除する
	q.push(100);
	cout << q.top() << endl; //100
}