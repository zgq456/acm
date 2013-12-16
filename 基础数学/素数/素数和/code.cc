#include <iostream>
#include <vector>
using namespace std;

const int limit = 100001;

vector<int> a(limit);

void preprocess(void) {
  vector<bool> visit(limit);

  for (int i = 2; i * i < limit; i++) {
    if (visit[i]) continue;
    for (int j = i * i; j < limit; j += i)
      visit[j] = true;
  }

  vector<int> prime;
  for (int i = 2; i < limit; i++) {
    if (visit[i]) continue;
    for (vector<int>::iterator it = prime.begin();
         it != prime.end();
         ++it) {
      int sum = *it + i;
      if (sum < limit)
        a[sum]++;
    }
    prime.push_back(i);
  }
}

int process(int n) {
  return a[n];
}

int main(void) {
  preprocess();

  int n;
  while (cin >> n)
    cout << process(n) << endl;
  
  return 0;
}
