#include<bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row){
    long long res = 1;
    vector<int> ans;
    ans.push_back(1);
    for (int col = 1; col < row; col++)
    {
        res = res * (row-col);
        res = res / col;
        ans.push_back(res);
    }
    return ans;
}
// Time Complexity -> O(n*n),Space Complexity -> O(n*n).
vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++)
    {
        res.push_back(generateRow(i));
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> res = pascalTriangle(n);
    for(auto row : res){
        for(auto val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}