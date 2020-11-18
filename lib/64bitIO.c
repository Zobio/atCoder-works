#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//intN_t型の使用にはstdint.hが必要 プレースホルダ用にinttypes.hが必要
//プレースホルダ http://www.c-tipsref.com/reference/inttypes.html

int main() {
    int64_t n;
    scanf("%" SCNd64, &n);
	printf("%" PRId64 "\n", n); //改行には一度ダブルクォートを閉じてPRId64を入れる必要あり
								//%の直後のPRId64はプレースホルダと解釈されない
}