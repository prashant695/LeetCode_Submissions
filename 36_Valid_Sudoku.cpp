// Method_1
// BruteForce
class Solution {
  public:
    bool isValidSudoku(vector < vector < char >> & board) {
      map < int, int > m;
      for (int i = 0; i < 9; i++) {
        m.clear();
        for (int j = 0; j < 9; j++) {
          if (board[i][j] != '.') {
            if (m[board[i][j] - '0']) {
              return false;
            } else m[board[i][j] - '0']++;
          }
        }
      }
      m.clear();
      for (int i = 0; i < 9; i++) {
        m.clear();
        for (int j = 0; j < 9; j++) {
          if (board[j][i] != '.') {
            if (m[board[j][i] - '0']) {
              return false;
            } else m[board[j][i] - '0']++;
          }
        }
      }
      m.clear();
      for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
          m.clear();
          for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
              if (board[i + k][j + l] != '.') {
                if (m[board[i + k][j + l] - '0']) return false;
                else m[board[i + k][j + l] - '0']++;
              }
            }
          }
        }
      }
      return true;
    }
};

// Method_2
class Solution {
  public:
    bool isValidSudoku(vector < vector < char >> & board) {
      int row[9] = {
        0
      }, col[9] = {
        0
      }, block[9] = {
        0
      }, p;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if (board[i][j] != '.') {
            p = 1 << ((board[i][j] - '0') - 1);
            if (row[i] & p) return false;
            row[i] |= p;

            if (col[j] & p) return false;
            col[j] |= p;

            if (block[(i / 3) * 3 + (j / 3)] & p) return false;
            block[(i / 3) * 3 + (j / 3)] |= p;
          }
        }
      }
      return true;
    }
};