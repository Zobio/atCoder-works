#include <stdio.h>

/* 与えられた並びpの次に大きい並べ替えを返す */
int next_perm(int *p, int n)
{
  int i, j, k, tmp;

  /* 上位桁のほうが下位桁よりも小さいところまで移動 */
  for(i = n - 1; i > 0 && p[i-1] >= p[i]; i--);

  /* pが最大(次の並べ替えがない) */
  if(i == 0) return 0;

  /* p[i-1]より値の大きい最も下位の桁をp[j]とする */
  for(j = n - 1; j > i && p[i-1] >= p[j]; j--);

  /* p[i-1]とp[j]とを交換 */
  tmp = p[i-1], p[i-1] = p[j], p[j] = tmp;

  /* p[i]から最下位までを逆順 なぜならp[i-1]とp[j]の間に逆順が対応しない(p[i-1] < p[j])
  があったらそこで交換が起きるはずだから*/
  for(k = 0; k <= ((n-1)-i)/2; k++)
    tmp = p[i+k], p[i+k] = p[(n-1)-k], p[(n-1)-k] = tmp;

  return 1;
}

int main(void)
{
  int p[4] = {0, 1, 1, 2};
  int i;

  /* 並べ替え */
  do {
    for(i = 0; i < 4; i++)
      printf("%d", p[i]);
    printf("\n");
  } while(next_perm(p, 4));

  return 0;
}