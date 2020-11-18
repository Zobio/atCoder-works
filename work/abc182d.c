#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
	int n;
	int64_t ans = 0;
	int64_t now = 0;
	int64_t maxMove = 0;
	int64_t move = 0;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		move += a[i];		  //開始点を座標0としたときの動作iの移動距離
		if (maxMove < move) { //過去の移動距離の最高値と動作iの移動距離の比較 最高値だったら代入
			maxMove = move;
		}
		if (now + maxMove > ans) { //今の地点と最高値の移動後の地点が最高値なら代入
			ans = now + maxMove;
		}
		now += move;  //移動した後の地点
	}
	printf("%" PRId64 "\n", ans);
}