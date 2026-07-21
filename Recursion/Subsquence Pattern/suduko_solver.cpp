#include<bits/stdc++.h>
using namespace std;
  
bool isValid(vector<vector<char>>& input, int row, int col, char c) {
    for (int i = 0; i < 9; i++)
    {
        if(input[row][i] == c) return false;
        if(input[i][col] == c) return false;
        if(input[3 * (row / 3)+ (i / 3)][3 * (col / 3) + (i % 3)] == c) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& input){
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[0].size(); j++)
        {
            if(input[i][j] == '.'){
                for (char c = '1'; c <= '9'; c++)  
                {
                    if(isValid(input,i,j,c)) {
                        input[i][j] = c;
                        if(solve(input) == true){
                            return true;
                        }else{
                            input[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoko(vector<vector<char>>& input) {
    solve(input);
}             
                   
int main() {
    vector<vector<char>> input = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    for(auto &it : input){
        for(auto &val : it){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
    solveSudoko(input);
    for(auto &it : input){
        for(auto &val : it){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}