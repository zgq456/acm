#include <math.h>
#include <stdio.h>

int main(void) {
  int n;

  while (scanf("%d", &n), n)
    printf("%.0f %.0f\n", pow(5, n) - 4, pow(4, n) + n - 4);

  return 0;
}
