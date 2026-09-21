#include<bits/stdc++.h>
using namespace std;
                   
// T.C -> O(N * 2^N) , S.C -> O(2^N * N).
vector<vector<int>> generateSubSets(vector<int>& num) {
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << num.size()); i++)
    {
        vector<int> list;
        for (int j = 0; j < num.size(); j++)
        {
            if(i & (1 << j)){
                list.push_back(num[j]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}    

int main() {
    vector<int> set = {1,2,3};
    vector<vector<int>> ans = generateSubSets(set);
    for(auto it : ans) {
        for(auto row : it) {
            cout << row ;
        }
        cout << endl;
    }
    return 0;
}