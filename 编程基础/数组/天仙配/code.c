#include <stdio.h>

int main(void) {
  int n, x[20000];
  int count, i;
  int idx, idy;
  int prefix, suffix;

  while (scanf("%d", &n), n) {
    for (i = 0; i < 2*n && scanf("%d", x + i); i++);
    count = 0;
    idx = 0;
    idy = 2 * n - 1;
    prefix = 0;
    suffix = 0;
    while (idx < 2*n && idy > -1) {
      if (prefix < suffix)
        prefix += x[idx++];
      else if (prefix > suffix)
        suffix += x[idy--];
      else {
        prefix += x[idx++];
        suffix += x[idy--];
        count++;
      }
    }
    printf("%d\n", count);
  }

  return 0;
}
