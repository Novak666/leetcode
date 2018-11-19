#include <iostream>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if(row < 1)
            return;
        col = board[0].size();
        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][col - 1] == 'O')
                dfs(board, i, col - 1);
        }
        for(int j = 0; j < col; j++){
            if(board[0][j] == 'O')
                dfs(board, 0, j);
            if(board[row - 1][j] == 'O')
                dfs(board, row - 1, j);
        }
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'S')
                    board[i][j] = 'O';
            }

    }
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= row || j >= col)
            return;
        if(board[i][j] == 'O'){
            board[i][j] = 'S';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
    }
private:
    int row, col;
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
