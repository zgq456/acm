#include <stdio.h>

int main(void) {
  int i, f[41] = {1, 1, 2};

  for (i = 3; i < 41; i++)
    f[i] = f[i-1] + f[i-2];

  while (scanf("%d", &i), i)
    printf("%d\n", f[i]);

  return 0;
}
