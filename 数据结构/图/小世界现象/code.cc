#include <iostream>
#include <queue>
using namespace std;

class Friend {
private:
  int size;
  bool relation[51][51];
public:
  Friend(int s);
  void load();
  bool isFriend(int a, int b);
  int degrees(int a, int b);
};

Friend::Friend(int s): size(s) {
}


void Friend::load() {
  int r;
  for (int y = 1; y <= size; y++) {
    for (int x = 1; x <= size; x++) {
      cin >> r;
      relation[y][x] = r == 1;
    }
  }
}

bool Friend::isFriend(int a, int b) {
  return relation[a][b];
}

typedef struct {
  int id;
  int step;
} node;

int Friend::degrees(int a, int b) {
  node from = {a, 0};

  bool visit[51][51] = {false};
  for (int i = 1; i <= size; i++) {
    visit[i][i] = true;
  }
  
  queue<node> q;
  q.push(from);
  while (!q.empty()) {
    from = q.front();
    q.pop();

    if (from.id == b) {
      return from.step - 1;
    }
    for (int i = 1; i <= size; i++) {
      if (relation[from.id][i]
       && !visit[from.id][i]) {
        visit[from.id][i] = visit[i][from.id] = true;
        node to = {i, from.step + 1};
        q.push(to);
      }
    }
  }
  return -1;
}

int main(void) {
  int t, n;

  cin >> t;
  while (t-- && cin >> n) {
    Friend f(n);
    f.load();

    int m, a, b;
    cin >> m;
    while (m-- && cin >> a >> b) {
      int d = f.degrees(a, b);
      if (d < 0) {
        cout << "Sorry" << endl;
      } else {
        cout << d << endl;
      }
    }
  }
}
