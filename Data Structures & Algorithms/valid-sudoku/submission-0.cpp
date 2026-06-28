
class Solution {
  public:

    bool isDuplicate(std::string str) {
      int seen[10] = {0};
      int i = 0;
      while (i < str.length()) {
        if (str[i] >= '1' && str[i] <= '9') {
          if (seen[str[i] - '1'] == 1) {
            return true;
          }
          else {
            seen[str[i] - '1'] = 1;
          }
        }
        i++;
      }
      return false;
    }

    bool check_sub_box(std::vector<std::vector<char>>& board) {
      int k = 0;
      while (k < board.size()) {
        int i = 0;
        std::string str;
        while(i < board.size()) {
          int j = 0;
          while (j < board[i].size() / 3) {
            str += board[i][j + k];
            j++;
          }
          if (str.length() == 9) {
            if (isDuplicate(str)) {
              return false;
            }
            str = "";
          }
          i++;
        }
        k += 3;
      }
      return true;
    }

    bool column_board(std::vector<std::vector<char>>& board) {
      int  i = 0;
      while (i < board.size()) {
        int j = 0;
        std::string str;
        while (j < board[i].size()) {
          str += board[j][i];
          j++;
        }
        if (isDuplicate(str)) {
          return false;
        }
        i++;
      }
      return true;
    }

    bool row_board(std::vector<std::vector<char>>& board) {
      int  i = 0;
      while (i < board.size()) {
        int j = 0;
        std::string str;
        while (j < board[i].size()) {
          str += board[i][j];
          j++;
        }
        if (isDuplicate(str)) {
          return false;
        }
        i++;
      }
      return true;
    }

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
      if (!check_sub_box(board)) {
        return false;
      }
      if (!row_board(board)) {
        return false;
      }
      if (!column_board(board)) {
        return false;
      }
      return true;
    }
};
