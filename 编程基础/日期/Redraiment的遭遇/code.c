#include <stdio.h>

int main(void) {
  int i, j;
  char t[63] = {0};

  for (j = 2, i = 1; i < 63 && (t[i] = 1); i += j, j++);
  for (i = 61; i; t[i] += t[i+1], i--);

  while (scanf("%d/%d", &i, &j), i+j)
    printf("%d\n", t[i == 7 ? j : j + 31]);

  return 0;
}
