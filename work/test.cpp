#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int N,M; //頂点と辺の数
vector<vector<int>> G; //グラフ
vector<int> h; //入次数
vector<int> l_depth; //最大経路長
vector<int> ans; //答えを格納

void topoBFS(){   
	queue<int> unchecked;
	for(int i=0; i<N; i++){
		if(h[i]==0){
			unchecked.push(i); //入次数が0の頂点をキューに入れる
			l_depth[i] = 0; //そのような頂点は深さが0
		}
	}
	while(!unchecked.empty()){
		int current = unchecked.front();
		unchecked.pop();
		ans.push_back(current); //キューから取り出したらすぐソート後のリストに加える

		for(int next: G[current]){ //「行ける」頂点について
			h[next]--; //入次数を減らす
			l_depth[next] = max(l_depth[next], l_depth[current]+1); //最長経路
			if(h[next]==0){ //入次数0になったらキューに追加
			unchecked.push(next);
			}
		}
	}
}

int main(){
	cin >> N >> M;
	G.resize(N);
	h.resize(N, 0); //入次数0初期化
	for (int i = 0; i < M; i++) {
		int f, t;
		cin >> f >> t;
		//f--; t--; //1始まりで辺の情報を入れるならデクリメントする
		G[f].push_back(t); //fからtに行ける
		h[t]++;			   //tの入次数を増やす
	}

	l_depth.resize(N, -1);
	topoBFS();

	bool isDAG = ans.size()==N; //DAGであるかどうか
	if(isDAG){
		for(int x: ans){
			cout<<x<<endl; //1始まりで出力するときはx+1とする
		}
	}else{
		cout<<"not DAG"<<endl;
	}
}