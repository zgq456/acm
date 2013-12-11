#include <stdio.h>

int main(void) {
  char c;

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '<':
        printf("&gt;");
        break;
      case '>':
        printf("&lt;");
        break;
      case ' ':
        printf("&nbsp;");
        break;
      case '\t':
        printf("&#9;");
        break;
      default :
        putchar(c);
        break;
    }
  }

  return 0;
}
