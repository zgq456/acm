#include <stdio.h>
#include <string.h>

int top = 0;
int stack[32];
char sym[32] = "#";
const int res[2][9] = {
  {0, 1, 2, 3, 4, 5, 6, 7, 8},
  {0, 1, 1, 3, 3, 5, 0, 0, 8}
};

int judge(char x) {
  switch (x) {
    case 0  : return 0;
    case '#': return 0;
    case '+': return 1;
    case '-': return 2;
    case '*': return 3;
    case '/': return 4;
    case '^': return 5;
    case '(': return 6;
    case ')': return 7;
    default : return 8;
  }
}

char* sol(char *s) {
  int i;
  char min = '^';

  for (;*s && *s != ')'; s++) {
    if (res[0][judge(min)] > res[0][judge(*s)]) min = *s;
    if (*s == '(') {
      stack[top++] = s - sym;
      s = sol(s + 1);
    }
  }
  i = stack[--top] - 1;
  if (
    (res[1][judge(min)] > res[1][judge(sym[i])] ||
    (res[1][judge(min)] == res[1][judge(sym[i])] &&
    (sym[i] == '+' || sym[i] == '*')))
    && res[1][judge(min)] >= res[1][judge(*(s+1))]
     )
    sym[i+1] = *s = ' ';
  return s;
}

int main(void) {
  int i;

  while (scanf("%s", sym + 1), sym[1] - '#') {
    sol(sym + 1);
    for (i = 1; sym[i]; i++)
      if (sym[i] != ' ')
        putchar(sym[i]);
    putchar('\n');
    memset(sym, 0, sizeof(sym));
    sym[0] = '#';
    top = 0;
  }

  return 0;
}
