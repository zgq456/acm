#include <iostream>
using namespace std;

int data[] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1
};

void process(int x, int y) {
  for (x += 39, y += 39; data[x] && x <= y ; x++);
  puts(x > y ? "OK" : "Sorry");
}

int main(void) {
  int x, y;
  
  while (cin >> x >> y, x != 0 || y != 0)
    process(x, y);

  return 0;
}
