#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int n = 0;
	scanf("%d", &n);
	double x[n];
	double y[n];
	double m[n][n]; //一個目<二個目
	double b[n][n]; //y=0の時の座標
	bool yet[n][n];
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			m[i][j] = 0;
			b[i][j] = 0;
			yet[i][j] = false;
		}
		x[i] = 0;
		y[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		scanf("%f", &x[i]);
		scanf("%f", &y[i]);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			m[i][j] = (x[i] - x[j]) / (y[i] - y[j]);
			b[i][j] = x[i] - y[i] * m[i][j];
			yet[i][j] = true;
			printf("m[%d][%d] = %d\n", i, j, m[i][j]);
			printf("b[%d][%d] = %d\n", i, j, b[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++) {
				for(int l = 0; l < n; l++) {
					if((m[i][j] == m[k][l]) && yet[i][j] && yet[k][l]){
					puts("Yes");
					return 0;
					}
				}
			}
		}
	}
	puts("No");
	return 0;
 }