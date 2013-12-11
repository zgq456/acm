#include <stdlib.h>
#include <stdio.h>

typedef struct homework {
  int time;
  int value;
}* Homework;

int cmp(const void* a, const void* b) {
  Homework m = (Homework) a;
  Homework n = (Homework) b;
  return m->time * n->value - n->time * m->value;
}

int main(void) {
  struct homework list[20];
  int n, total;
  
  while (scanf("%d%d", &n, &total), n + total) {
    double value = 0;
    int i;

    for (i = 0; i < n; i++) {
      scanf("%d%d", &list[i].time, &list[i].value);
    }

    qsort(list, n, sizeof(struct homework), cmp);

    for (i = 0; i < n && total > 0; i++) {
      if (total >= list[i].time) {
        value += list[i].value;
        total -= list[i].time;
      } else {
        value += 1.0 * list[i].value * total / list[i].time;
        total = 0;
      }
    }
    printf("%.2f\n", value);
  }

  return EXIT_SUCCESS;
}
