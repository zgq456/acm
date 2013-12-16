#include <iostream>
using namespace std;

#define limit 92

typedef long long LL;

LL f[limit] = {1ll, 1ll, 2ll};

void preprocess() {
  for (int i = 3; i < limit; i++)
    f[i] = f[i - 1] + f[i - 2];
}

LL process(int from, int to) {
  return f[to - from];
}

int main(void) {
  preprocess();

  int n, from, to;
  cin >> n;
  while (n-- && cin >> from >> to)
    cout << process(from, to) << endl;
  
  return 0;
}
