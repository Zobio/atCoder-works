#include<stdio.h>

//next_permutation
int nexp(int*a,int cnt){
	int l=cnt-1,r=cnt-1;
	int ret=0;
	int t;
	while(--l>=0&&a[l]>=a[l+1]);
	if(l>=0){
		ret=1;
		while(a[l]>=a[r])r--;
		t=a[l];a[l]=a[r];a[r]=t;
	}
	for(l++,r=cnt-1;l<r;l++,r--)
	t=a[l],a[l]=a[r],a[r]=t;
	return ret;
}

int t[9][9];
int idx[9];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
	scanf("%d",&t[i][j]);
	for(int i=0;i<n;i++)
	idx[i]=i;
	
	int ans=0;
	do{
		int time=0;
		for(int i=0;i<n;i++)
		time+=t[idx[i]][idx[(i+1)%n]];
		if(time==k)
		ans++;
	}while(nexp(idx+1,n-1));
	printf("%d\n",ans);
}
