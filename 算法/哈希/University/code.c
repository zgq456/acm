#include <ctype.h>
#include <stdio.h>

int main(void) {
  char c, hash[2][27] = {
    "ECFAJKLBDGHIVWZYMNOPQRSTUX",
    "erwqtyghbnuiopsjkdlfazxcvm"
  };

  while ((c = getchar()) - '#') {
    if (isupper(c))
      putchar(hash[0][c-'A']);
    else if (islower(c))
      putchar(hash[1][c-'a']);
    else
      putchar(c);
  }

  return 0;
}
