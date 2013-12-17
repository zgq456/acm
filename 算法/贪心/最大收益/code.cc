#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double total_return(vector<int>& price) {
  double amount = 10000.0;

  for (int i = 0; i < price.size(); i++) {
    int j;
    for (j = i;
         j + 1 < price.size()
      && price[j] <= price[j + 1];
         j++);
    if (i < j) {
      amount *= 1.0 * price[j] / price[i];
      i = j;
    }
  }

  return amount;
}

int main(void) {
  int n;

  while (cin >> n) {
    vector<int> price(n);
    for (int i = 0; i < price.size(); i++)
      cin >> price[i];
    cout << fixed << setprecision(2)
         << total_return(price) << endl;
  }

  return 0;
}
