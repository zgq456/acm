#include <stdio.h>

int main(void) {
  int w, n;
  int t, v, m;
  const int max = 0x7fffffff;

  while (scanf("%d%d", &w, &n), w + n) {
    for (m = max, w *= 1000; n-- && scanf("%d%d", &t, &v);) {
      if (t < 1 && v > 0 && m > (w - t) / v)
        m = (w - t) / v;
    }
    if (m == max) {
      puts("Can't Solve");
    } else {
      printf("%d\n", m);
    }
  }

  return 0;
}
