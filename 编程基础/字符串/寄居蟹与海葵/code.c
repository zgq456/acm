#include <stdio.h>

char A[1000001], B[1000001];

int main(void) {
  int ida, idb;

  while (scanf("%s%s", A, B), A[0] - '0') {
    for (ida = idb = 0; A[ida] && B[idb];) {
      if (A[ida] + B[idb] - 'A' == 'Z') {
        ida++;
        idb++;
      } else {
        ida++;
      }
    }
    puts(B[idb] ? "No" : "Yes");
  }

  return 0;
}
