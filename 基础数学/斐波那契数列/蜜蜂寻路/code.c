#include <stdio.h>

#define limit 92

typedef long long LL;

LL f[limit] = {1ll, 1ll, 2ll};

LL process(int from, int to) {
  return f[to - from];
}

int main(void) {
  int i, n, from, to;

  for (i = 3; i < limit; i++)
    f[i] = f[i-1] + f[i-2];

  scanf("%d", &n);
  while (n-- && scanf("%d%d", &from, &to)) {
    printf("%lld\n", process(from, to));
  }

  return 0;
}
