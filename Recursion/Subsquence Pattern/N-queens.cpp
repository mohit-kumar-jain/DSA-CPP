#include<bits/stdc++.h>
using namespace std;
    
// T.C -> O(N! * N), S.C -> O(N*N + N).

bool isSafe(int row, int col, vector<string>& board, int n) {
    int duprow = row;
    int dupcol = col;
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;col--;
    }
    row = duprow;
    col = dupcol;
    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }
    col = dupcol;
    row = duprow;
    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false;
        row++;col--;
    }
    return true;
}

void solve(int col, vector<string>& board, int n, vector<vector<string>>& ans){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row = 0; row < n;row++){
        if(isSafe(row,col,board,n)){
            board [row][col] = 'Q';
            solve(col + 1, board, n, ans);
            board [row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<string> board(n);
    vector<vector<string>> ans;
    string s(n,'.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0,board,n,ans);
    return ans;
}               
                   
int main() {
    int n = 10;
    vector<vector<string>> res;
    res =solveNQueens(n);
    for(auto &it : res) {
        for (auto &row : it) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}