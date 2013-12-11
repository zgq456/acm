#include <stdlib.h>
#include <stdio.h>
 
#define swap(h, i) do { \
    int tmp = list[h]; \
    list[h] = list[i]; \
    list[i] = tmp; \
  } while(0)

typedef enum {
  false = 0,
  true = !false
} bool;

bool next_permutation(int list[], size_t size) {
  size_t head_item;
  size_t item;

  // find the sub completed list
  for (item = size - 1; item > 0; item--) {
    if (list[item - 1] < list[item]) {
      break;
    }
  }

  if (item == 0) {
    // finished
    return false;
  } else {
    head_item = item - 1;
  }

  // find the next item:
  // The first great than head_item
  for (item = size - 1; item > head_item; item--) {
    if (list[head_item] < list[item]) {
      break;
    }
  }
  swap(head_item, item);

  // reverse the sub list
  for (item = head_item + 1; item < size; item++, size--) {
    swap(item, size - 1);
  }

  return true;
}

int prime[3432] = {0};

void create_prime() {
  int i, j, a[32000] = {true, true, false};

  for (i = 2; i * i < 32000; i++) {
    if (a[i]) continue;
    for (j = i * i; j < 32000; j += i)
      a[j] = true;
  }

  j = 0;
  for (i = 2; i < 32000; i++)
    if (!a[i])
      prime[j++] = i;
}

bool is_prime(int n) {
  int i;
  if (n < 2) return false;
  for (i = 0; prime[i] * prime[i] <= n; i++) {
    if (n % prime[i] == 0)
      return false;
  }
  return true;
}

int to_i(int list[], int len) {
  int i, n = 0;
  for (i = 0; i < len; i++) {
    n = n * 10 + list[i];
  }
  return n;
}

int cmp(const void* a, const void* b) {
  int* m = (int*) a;
  int* n = (int*) b;
  return *m - *n;
}

int main(void) {
  int i, n, list[9];

  create_prime();
  while (scanf("%d", &n), n) {
    int count, sum = 0;

    for (i = 0; i < n; i++) {
      scanf("%d", list + i);
      sum += list[i];
    }
    if (sum > 3 && sum % 3 == 0) {
      puts("NONE\n");
      continue;
    }

    qsort(list, n, sizeof(int), cmp);

    count = 0;
    do {
      int p = to_i(list, n);
      if (is_prime(p)) {
        printf("%d\n", p);
        count++;
      }
    } while (next_permutation(list, n));
    if (count == 0)
      puts("NONE");
    putchar('\n');
  }

  return EXIT_SUCCESS;
}
