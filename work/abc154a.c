#include <stdio.h>
#include <string.h>

int main(void) {
    char s [11];
    char t [11];
    int a = 0;
    int b = b;
    char u [11];
    scanf("%s", s);
    scanf("%s", t);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%s", u);
    if(!strcmp(s, u)) {
        printf("%d %d\n", a - 1,  b);
    }else{
        printf("%d %d\n", a,  b - 1);
    }
    return 0;
}