#include <math.h>
#include <stdio.h>

int main(void)
{
  int n;

  while (scanf("%d", &n), n)
    printf("%.0f\n", 3 * pow(2, n - 1) - 2);

  return 0;
}
