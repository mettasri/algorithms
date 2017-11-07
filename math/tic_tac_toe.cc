#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#define I ' ' // Empty cells
#define O 'O' // player 1
#define X 'X' // player 2

bool validate(vector<vector<char>>& m) {
  int left_diag_count = 0;
  int right_diag_count = 0;
  for (int r = 0; r < m.size(); ++r) {
    int row_count = 0;
    int col_count = 0;
    for (int c = 0; c < m[r].size(); ++c) {
      if (m[r][c] == 'X') {
        row_count++;
      } else if (m[r][c] == 'O') {
        row_count--;
      }

      if (m[c][r] == 'X') {
        col_count++;
      } else if (m[c][r] == 'O') {
        col_count--;
      }

      if (r == c && m[r][r] == 'X') {
        left_diag_count++;
      } else if (r == c && m[r][r] == 'O') {
        left_diag_count--;
      }

      if ((r + c) == (m.size() - 1) && m[r][c] == 'X') {
        right_diag_count++;
      } else if ((r + c) == (m.size() - 1) && m[r][c] == 'O') {
        right_diag_count--;
      }

      if (abs(row_count) == m.size() || abs(col_count) == m.size() ||
          abs(right_diag_count) == m.size() || abs(left_diag_count) == m.size()) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  vector<vector<char>> matrix1X = {
        {X, X, X},
        {I, I, O},
        {I, O, O},
      };
  true == validate(matrix1X) ? cout << "1X PASS\n" : cout << "1X FAIL\n";

  vector<vector<char>> matrix2X = {
        {I, I, O},
        {X, X, X},
        {I, O, O},
      };
  true == validate(matrix2X) ? cout << "2X PASS\n" : cout << "2X FAIL\n";

  vector<vector<char>> matrix3X = {
        {I, I, O},
        {I, O, O},
        {X, X, X},
      };
  true == validate(matrix3X) ? cout << "3X PASS\n" : cout << "3X FAIL\n";

  vector<vector<char>> matrix4X = {
        {X, I, O},
        {X, O, O},
        {X, O, X},
      };
  true == validate(matrix4X) ? cout << "4X PASS\n" : cout << "4X FAIL\n";

  vector<vector<char>> matrix5X = {
        {I, X, O},
        {O, X, O},
        {O, X, X},
      };
  true == validate(matrix5X) ? cout << "5X PASS\n" : cout << "5X FAIL\n";

  vector<vector<char>> matrix6X = {
        {I, O, X},
        {O, O, X},
        {O, X, X},
      };
  true == validate(matrix6X) ? cout << "6X PASS\n" : cout << "6X FAIL\n";

  vector<vector<char>> matrix7X = {
        {X, O, X},
        {O, X, O},
        {O, X, X},
      };
  true == validate(matrix7X) ? cout << "7X PASS\n" : cout << "7X FAIL\n";

  vector<vector<char>> matrix8X = {
        {I, O, X},
        {O, X, O},
        {X, X, O},
      };
  true == validate(matrix8X) ? cout << "8X PASS\n" : cout << "8X FAIL\n";

  vector<vector<char>> matrix9X = {
        {I, O, X},
        {O, I, O},
        {O, X, X},
      };
  false == validate(matrix9X) ? cout << "9X PASS\n" : cout << "9X FAIL\n";


  vector<vector<char>> matrix1O = {
        {O, O, O},
        {I, I, X},
        {I, X, X},
      };
  true == validate(matrix1O) ? cout << "1O PASS\n" : cout << "1O FAIL\n";

  vector<vector<char>> matrix2O = {
        {I, I, X},
        {O, O, O},
        {I, X, X},
      };
  true == validate(matrix2O) ? cout << "2O PASS\n" : cout << "2O FAIL\n";

  vector<vector<char>> matrix3O = {
        {I, I, X},
        {I, X, X},
        {O, O, O},
      };
  true == validate(matrix3O) ? cout << "3O PASS\n" : cout << "3O FAIL\n";

  vector<vector<char>> matrix4O = {
        {O, I, X},
        {O, X, X},
        {O, X, O},
      };
  true == validate(matrix4O) ? cout << "4O PASS\n" : cout << "4O FAIL\n";

  vector<vector<char>> matrix5O = {
        {I, O, X},
        {X, O, X},
        {X, O, O},
      };
  true == validate(matrix5O) ? cout << "5O PASS\n" : cout << "5O FAIL\n";

  vector<vector<char>> matrix6O = {
        {I, X, O},
        {X, X, O},
        {X, O, O},
      };
  true == validate(matrix6O) ? cout << "6O PASS\n" : cout << "6O FAIL\n";

  vector<vector<char>> matrix7O = {
        {O, X, O},
        {X, O, X},
        {X, O, O},
      };
  true == validate(matrix7O) ? cout << "7O PASS\n" : cout << "7O FAIL\n";

  vector<vector<char>> matrix8O = {
        {I, X, O},
        {X, O, X},
        {O, O, X},
      };
  true == validate(matrix8O) ? cout << "8O PASS\n" : cout << "8O FAIL\n";


}
