#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(n),Space Complexity -> O(n).
void generateRow(int row){
    long long res = 1;
    vector<int> ans;
    ans.push_back(1);
    for (int col = 1; col < row; col++)
    {
        res = res * (row-col);
        res = res / col;
        ans.push_back(res);
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    generateRow(n);
    
    return 0;
}