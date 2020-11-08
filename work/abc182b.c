#include<stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int a[n];
	int max = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(a[i] > max){
			max = a[i];
		}
	}
	int count = 0;
	int answer = 0;
	int answerNum = 0;
	for(int i = 1; i < max; i++) {
		for(int j = 0; j < n; j++) {
			if(a[j] % (i + 1) == 0)
			count++;
		}
		if(answer < count){
		answer = count;
		answerNum = i + 1;
		}
		count = 0;
	}
	printf("%d", answerNum);
}