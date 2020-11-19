#include<stdio.h>
int main(){
  int n,x[110],y[110],i,j,k,a,b,c,d;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]);
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(k=j+1;k<n;k++){
	a=x[i]-x[k];
	b=y[i]-y[k];
	c=x[j]-x[k];
	d=y[j]-y[k];
	if(a*d==c*b){
	  printf("Yes\n");
	  return 0;
	}
      }
    }
  }
  printf("No\n");
  return 0;
}
	
