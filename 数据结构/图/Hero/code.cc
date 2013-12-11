#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
  int x;
  int y;
}node;

int n, m;
int map[20][20];
char mp[21][21];

bool ac(node &nd) {
  return nd.x < n && nd.x >= 0 && nd.y < m && nd.y >= 0 && map[nd.y][nd.x] == -1 && mp[nd.y][nd.x] != '*';
}

int bfs(node &begin, node &end) {
  int i, j;
  node t;
  queue <node> q;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++)
      map[i][j] = -1;
  }
  map[begin.y][begin.x] = 0;
  for (q.push(begin); !q.empty(); q.pop()) {
    if (q.front().x == end.x && q.front().y == end.y)
      return map[end.y][end.x];
    t = q.front();t.x++;
    if (ac(t)) {
      q.push(t);
      map[t.y][t.x] = map[(q.front()).y][(q.front()).x] + 1;
    }
    t = q.front();t.y++;
    if (ac(t)) {
      q.push(t);
      map[t.y][t.x] = map[(q.front()).y][(q.front()).x] + 1;
    }
    t = q.front();t.x--;
    if (ac(t)) {
      q.push(t);
      map[t.y][t.x] = map[(q.front()).y][(q.front()).x] + 1;
    }
    t = q.front();t.y--;
    if (ac(t)) {
      q.push(t);
      map[t.y][t.x] = map[(q.front()).y][(q.front()).x] + 1;
    }
  }

  return 0x7ffffff;
}

int main(void) {
  node b, e;
  char *p;
  int i, t;

  while (scanf("%d%d%d%*c", &n, &m, &t), m+n+t) {
    for (i = 0; i < m && gets(mp[i]); i++) {
      if (p = strchr(mp[i], 'S')) {
        b.y = i;
        b.x = p - mp[i];
      }
      if (p = strchr(mp[i], 'P')) {
        e.y = i;
        e.x = p - mp[i];
      }
    }
    puts(bfs(b, e) > t ? "NO" : "YES");
  }

  return 0;
}
