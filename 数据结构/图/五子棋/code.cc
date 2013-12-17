#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(vector<string>& board, int y, int x) {
  int dir[4][2] = {
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1}
  };

  for (int d = 0; d < 4; d++) {
    int i;
    for (i = 1; i < 5; i++) {
      int dy = dir[d][0] * i + y;
      int dx = dir[d][1] * i + x;
      if (!(0 <= dx && dx < board.size()
         && 0 <= dy && dy < board.size()
         && board[y][x] == board[dy][dx])) {
        break;
      }
    }
    if (i >= 5) return true;
  }
  return false;
}

bool judge(vector<string>& board) {
  for (int y = 0; y < board.size(); y++)
    for (int x = 0; x < board.size(); x++)
      if (board[y][x] != '.' && check(board, y, x))
        return true;
  return false;
}

int main(void) {
  vector<string> board(20);
  
  while (cin >> board[0]) {
    for (int i = 1; i < board.size(); i++) {
      cin >> board[i];
    }
    cout << (judge(board)? "Yes": "No") << endl;
  }

  return 0;
}
