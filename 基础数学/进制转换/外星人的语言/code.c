#include <stdio.h>

void to_r(int n, int r) {
  int m;
  if (n > 0) {
    to_r(n / r, r);
    m = n % r;
    if (m < 10)
      putchar('0' + m);
    else
      putchar('A' + m - 10);
  }
}

int main(void) {
  int n, r;

  while (scanf("%d%d", &n, &r) != EOF) {
    to_r(n, r);
    putchar('\n');
  }
  
  return 0;
}
