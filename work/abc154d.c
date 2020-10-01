#include <stdio.h>

int main(void) {
    long n = 0;
    long k = 0;
    scanf("%d", &n);
    scanf("%d", &k);
    long p [n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    long max = 0;
    long nowNum = 0;
    long maxStart = 0;
    for(int i = 0; i < n - k; i++) {
        for(int j = i; j < i + k; j++) {
            nowNum += p[j];
        }
        if(nowNum > max) {
            maxStart = i;
        }
        nowNum = 0;
    }
    long sumPiece = 0;
    long sum = 0;
    for(int i = nowNum; i < nowNum + k; i++) {
        for(int j = 0; j < p[i]; j++) {
            sumPiece += j;
        }
        sum += sumPiece / i;
    }
    printf("%d", sum);
}