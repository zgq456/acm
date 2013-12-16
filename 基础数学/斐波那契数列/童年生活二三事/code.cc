#include <iostream>
using namespace std;

int fab[41] = {1ll, 1ll};

void preprocess() {
  for (int i = 2; i <= 40; i++)
    fab[i] = fab[i - 1] + fab[i - 2];
}

int process(int n) {
  return fab[n];
}

int main(void) {
  preprocess();

  int n;
  while (cin >> n, n)
    cout << process(n) << endl;

  return 0;
}
