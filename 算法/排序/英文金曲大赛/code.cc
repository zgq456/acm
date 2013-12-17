#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

double average(vector<double>& score) {
  double sum = accumulate(score.begin(), score.end(), 0.0);
  double max = *max_element(score.begin(), score.end());
  double min = *min_element(score.begin(), score.end());
  return (sum - min - max) / (score.size() - 2);
}

int main(void) {
  vector<double> score(7);
  string name;
  
  while (cin >> score[0]) {
    for (int i = 1; i < score.size(); i++)
      cin >> score[i];
    cin >> name;
    cout << name << " "
         << fixed << setprecision(2)
         << average(score) << endl;
  }

  return 0;
}
