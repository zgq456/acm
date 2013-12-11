#include <stdio.h>

int main(void) {
  int n;

  while (scanf("%d", &n), n) {
    int k;
    for (k = 0; n > 1; k++) {
      n = n / 3 + (n % 3? 1: 0);
    }
    printf("%d\n", k);
  }
  
  return 0;
}
