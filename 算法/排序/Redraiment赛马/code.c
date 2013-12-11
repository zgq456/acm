#include <stdlib.h>
#include <stdio.h>

int cmp(const void* a, const void* b) {
  int* m = (int*) a;
  int* n = (int*) b;
  return *n - *m;
}

int main(void) {
  int n, i, j, s;
  int A[2][1001];

  while (scanf("%d", &n), n) {
    for (i = 0; i < n && scanf("%d", A[0] + i); i++);
    for (i = 0; i < n && scanf("%d", A[1] + i); i++);
    qsort(A[0], n, sizeof(int), cmp);
    qsort(A[1], n, sizeof(int), cmp);
    for (i = j = s = 0; i < n && j < n;) {
      if (A[0][i] > A[1][j]) {
        i++;
        j++;
        s++;
      } else {
        j++;
      }
    }
    puts(s * 2 > n ? "YES" : "NO");
  }

  return 0;
}
