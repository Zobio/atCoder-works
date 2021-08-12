// D - Kth Excluded
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, q; cin>>n>>q;
	int64_t C[n]; for(int i=0; i<n; ++i) cin>>C[i], C[i] -= i+1;
	while(q--){
		int64_t k; cin>>k;
		cout<< k + lower_bound(C, C+n, k) - C <<endl;
	}
}
