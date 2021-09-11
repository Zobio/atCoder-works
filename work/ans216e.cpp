#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll a[N],n,m;
ll check(ll x){
	ll sum=0;
	for(ll i=1;i<=n;++i)
		sum+=max((ll)0,a[i]-x);
	return sum;
}
int main(){
	scanf("%lld %lld",&n,&m);
	ll sum=0;
	for(ll i=1;i<=n;++i)
		scanf("%lld",&a[i]),
		sum=max(sum,a[i]);
	ll l=0,r=sum,mid=(l+r)>>1,res=0;
	while(l<=r){
		if(check(mid)<=m)	res=mid,r=mid-1;
		else	l=mid+1;
		mid=(l+r)>>1;
	}
	m-=check(res);ll ans=0;
	for(ll i=1;i<=n;++i)
		if(a[i]>res)
			ans+=(a[i]+res+1)*(a[i]-res)/2;
	printf("%lld",ans+m*res);
	return 0;
}