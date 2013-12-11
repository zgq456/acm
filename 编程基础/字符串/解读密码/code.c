#include <stdio.h>
#include <ctype.h>

int main(void) {
  char c;
  while ((c = getchar()) != EOF) {
    if (isdigit(c) || c == '\n')
      putchar(c);
  }
  return 0;
}
