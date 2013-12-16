#include <iostream>
#include <vector>
using namespace std;

const int limit = 100001;

vector<int> a(limit);

void preprocess(void) {
  for (int i = 2; i * i < limit; i++) {
    if (a[i] > 0) continue;
    for (int j = i; j < limit; j += i)
      a[j]++;
  }
}

int process(int n) {
  return a[n]? a[n]: 1;
}

int main(void) {
  preprocess();

  int n;
  while (cin >> n)
    cout << process(n) << endl;
  
  return 0;
}
