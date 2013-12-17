#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double find_max(vector<double>& prices) {
  double min = prices[0];
  double max = 0.0;
  for (int i = 1; i < prices.size(); i++) {
    if (prices[i] < min) {
      min = prices[i];
    } else if (max < prices[i] - min) {
      max = prices[i] - min;
    }
  }
  return max;
}

int main(void) {
  vector<double> prices(9);
  
  while (cin >> prices[0]) {
    for (int i = 1; i < prices.size(); i++)
      cin >> prices[i];
    cout << fixed << setprecision(2)
         << find_max(prices) << endl;
  }

  return 0;
}
