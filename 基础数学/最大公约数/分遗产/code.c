#include <stdio.h>

#if 1
#define __DEF_GCD_
#elif 0
#define __QUICK__
#endif

typedef unsigned long UL;
#ifdef __DEF_GCD_
/*AC Total Time : 0MS*/
UL gcd(UL u, UL v) {
  int remainder;
  
  remainder = u % v;
  while(remainder) {
    u = v;
    v = remainder;
    remainder = u % v;
  }
  return v;
}

UL lcm(UL u, UL v) {
  return u * v / gcd(u, v);
}
#elif defined(__QUICK__)
/*AC Total Time : 0MS*/
UL lcm(UL u, UL v) {
  int i, max = u > v ? u : v, min = u < v ? u : v;
  for (i = max; i % min; i+= max);
  return i;
}
#else
/*Time Limit Exceeded*/
UL lcm(UL u, UL v) {
  int i;
  for (i = u > v ? u : v; i % u == 0 || i % v == 0; i++);
  return i;
}
#endif

int main(void) {
  int m, n, i;
  int son[10];
  int max, mu;

  while (scanf("%d%d", &m, &n), m + n) {
    for (max = 1, i = 0; i < n && scanf("%d", son + i); i++)
      max = lcm(son[i], max);
    for (i = mu = 0; i < n; i++)
      mu += max / son[i];
    if (m % mu) {
      puts("Can't Solve");
      continue;
    } else {
      mu = m / mu;
    }
    for (i = 0; i < n; i++)
      printf("%d%c", max / son[i] * mu, i < n-1 ? ' ' : '\n');
  }

  return 0;
}
