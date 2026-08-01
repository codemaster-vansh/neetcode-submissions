class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                if (board[i][j] != '.') {

                    char c = board[i][j];
                    int count = 0;
                    int x = i / 3, y = j / 3;
                    for (int i1 = x*3;i1 < (x + 1)*3;i1++) {
                        for (int j1 = y*3;j1 < (y + 1)*3;j1++) {
                            if (board[i1][j1] == c) count++;
                        }     
                    }

                    if (count > 1) return false;
                    count = 0;

                    for (int i1 = 0;i1 < 9;i1++) {
                        if (board[i1][j] == c) count++;
                    }

                    if (count > 1) return false;
                    count = 0;

                    for (int j1 = 0;j1 < 9;j1++) {
                        if (board[i][j1] == c) count++;
                    }

                    if (count > 1) return false;
                }
            }
        }
        return true;
    }
};
