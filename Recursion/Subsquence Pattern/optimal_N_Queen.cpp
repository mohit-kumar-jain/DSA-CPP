#include<bits/stdc++.h>
using namespace std;

void solve(int col, vector<string>& board,int n, vector<vector<string>>& ans,
     vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal) {
        if(col == n){
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0&& upperDiagonal[(n-1) + (col - row)] == 0 ) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[(n - 1)+(col - row)] = 1;
                solve(col + 1, board, n, ans , leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[(n - 1)+(col - row)] = 0;
                }
        }  
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftRow (n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0,board,n,ans,leftRow,lowerDiagonal,upperDiagonal);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> res;
    res = solveNQueens(n);
    for(auto &it : res) {
        for (auto &row : it) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}