#include <bits/stdc++.h>
using namespace std;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
	int n;
	cin >> n;
    vector<pair<int, int> > pairs(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pairs[i] = make_pair(a, b);
    }

    // b順にソート
    sort(pairs.begin(), pairs.end(), compare_by_b);

	//出力
	for(int i = 0; i < n; i++) {
		cout << pairs[i].first << " " << pairs[i].second << endl;
	}
}