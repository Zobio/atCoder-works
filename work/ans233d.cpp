#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(ll i=l;i<=r;i++)

signed main(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n);rep(i,0,n-1)cin>>a[i];
    vector<ll>s(n+1);rep(i,0,n-1)s[i+1]=s[i]+a[i];
    map<ll,ll>mp;
    ll ans=0;
    rep(r,1,n){//i番目で終わる連続部分列の中から総和がkであるものを探す
        mp[s[r-1]]++;
		cout << s[r - 1] << endl;
        ans += mp[s[r]-k];
		cout << s[r] - k << " " << mp[s[r] - k] << endl;
	}
    cout<<ans<<endl;
    return 0;
}
