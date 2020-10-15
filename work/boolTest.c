#include<stdio.h>
#include<stdbool.h>

int main(void) {
	bool yet[200000];
	int num = 0;
	int count = 0;
	for(int i = 0; i < sizeof(yet)/sizeof(bool); i++) {
		if(!yet)
		count++;
		num++;
	}
	printf("finished to %d count.\n", num);
	printf("result\ntrue:%d\nfalse:%d\n", 200000-num, num);
	return 0;
}