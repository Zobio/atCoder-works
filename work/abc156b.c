#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int a;
  int b;
  int c = 1;
  printf("%d", &a);
  printf("%d", &b);
  while(a >= b) {
    b *= b;
    c++;
  }
  printf("%d\n", c);
}