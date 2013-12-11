#include <stdio.h>

int main(void) {
  long long fab[91] = {1ll, 1ll};
  int i;

  for (i = 2; i <= 90; i++)
    fab[i] = fab[i - 1] + fab[i - 2];

  while (scanf("%d", &i), i)
    printf("%lld\n", fab[i]);

  return 0;
}
