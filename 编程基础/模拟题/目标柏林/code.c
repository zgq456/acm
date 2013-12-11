#include <stdio.h>
#include <string.h>

int main(void) {
  int i, j, len;
  char code[1024] = " ", tmp;

  while (gets(code + 1)) {
    len = strlen(code) - 1;
    for (i = len / 2; i; i--) {
      if (i % 2) {
        tmp = code[i];
        for (j = i; j + i <= len; j += i)
          code[j] = code[j + i];
        code[j] = tmp;
      } else {
        tmp = code[len/i*i];
        for (j = len/i*i; j; j -= i)
          code[j] = code[j - i];
        code[i] = tmp;
      }
    }
    puts(code + 1);
  }

  return 0;
}
