#include<bits/stdc++.h>
using namespace std;
              
bool cmp(vector<int>& first, vector<int>& second) {
    return first[1] < second[1];
}
int nonOverlap(vector<vector<int>>& interval) {
    sort(interval.begin(),interval.end(),cmp);
    int removeCnt = 0, freeTime = interval[0][1];
    for(int i = 1; i < interval.size(); i++) {
        if(interval[i][0] < freeTime){
            removeCnt++;
        }else{
            freeTime = interval[i][1];
        }
    }
    return removeCnt;
}                  
                   
int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    cout << nonOverlap(intervals) << endl;
    return 0;
}