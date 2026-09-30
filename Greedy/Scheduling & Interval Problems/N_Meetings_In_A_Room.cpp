#include<bits/stdc++.h>
using namespace std;
        
// T.C -> O(Nlog N), S.C -> O(N).
int maxMeetings(vector<int>& start, vector<int>& end){
    vector<pair<int,int>> meetings;
    for (int i = 0; i < start.size(); i++)
    {
        meetings.push_back({end[i],start[i]});
    }
    sort(meetings.begin() , meetings.end());
    int cnt = 0, freeTime = -1;
    for(const auto& meet : meetings) {
        if(meet.second > freeTime){
            cnt++;
            freeTime = meet.first;
        }
    }
    return cnt;
}                   
                   
int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5} ;
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(start,end) << endl;
    return 0;
}