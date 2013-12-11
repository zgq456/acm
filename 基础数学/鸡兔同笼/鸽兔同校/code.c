#include <stdio.h>

int main(void)
{
  int m, n;

  while (scanf("%d%d", &n, &m), m + n) {
    if (m % 2 || m > 4*n || m < 2*n) {
      puts("Error");
    } else {
      printf("%d %d\n", 2*n-m/2, m/2-n);
    }
  }

  return 0;
}
