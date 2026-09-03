class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, int>> rows, cols, squares;
        int N = board.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') continue;
                int row = rows[i][board[i][j]]++;
                int col = cols[j][board[i][j]]++;
                int square = ((i) / 3) * 3 + (j / 3);
                cout << "\ni,j :(" << i << "," << j << ")";
                cout << "\n|" << "Row val: " << row << " Col val: " << col << " square: " << square;
                squares[square][board[i][j]]++;
                if (rows[i][board[i][j]] > 1 || cols[j][board[i][j]] > 1 || squares[square][board[i][j]] > 1) {
                    cout << "\nFalse on (" << i << "," << j << ")";
                    cout << "\nRows: " << rows[i][board[i][j]];
                    cout << "\nCols: " << cols[j][board[i][j]];
                    cout << "\nSquare: " << squares[square][board[i][j]];
                    return false;
                }
            }
        }
        return true;
    }
};
