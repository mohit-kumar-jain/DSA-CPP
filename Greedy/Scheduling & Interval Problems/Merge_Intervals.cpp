#include<bits/stdc++.h>
using namespace std;
                  
// T.C -> O(N), S.C -> O(N).
vector<vector<int>> mergeIntervals(vector<vector<int>>& interval) {
    vector<vector<int>> res;
    for(int i = 0; i < interval.size(); i++) {
        if(res.empty() || res.back()[1] < interval[i][0]) {
            res.push_back(interval[i]);
        }
        else {
            res.back()[1] = max(res.back()[1], interval[i][1]);
        }
    }
    return res;
}             
                   
int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = mergeIntervals(intervals);
    for(auto it : res) {
        cout << "{";
        for(auto row : it) {
            cout  << row<< ", "; 
        }
        cout << "}";
    }
    return 0;
}