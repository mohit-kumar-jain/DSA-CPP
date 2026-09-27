#include<bits/stdc++.h>
using namespace std;
    
// T.C -> O(N + Nlog N) , S.C -> O(1).
double solve(vector<int>& bt) {
    int wtTime = 0, time = 0;
    sort(bt.begin(), bt.end());
    for (int i = 0; i < bt.size(); i++)
    {
        wtTime += time;
        time += bt[i];
    }
    return (double) (wtTime / bt.size());
}                   
                   
int main() {
    vector<int> bt = {1, 2, 3, 4};
    cout << solve(bt) << endl;
    return 0;
}