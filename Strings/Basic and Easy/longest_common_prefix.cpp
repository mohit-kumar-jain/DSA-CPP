#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(n*log n + M), S.C -> O(M).
string commonPrefix(vector<string> s){
    if(s.empty()) return "";
    sort(s.begin(),s.end());
    string ans = "", first = s[0], last = s[s.size()-1];
    int minLen = min(first.size(),last.size());
    for (int i = 0; i < minLen; i++)
    {
        if(first[i] != last[i])
            break;
        else
            ans += first[i];
    }
    return ans;
}

int main()
{
    vector<string> s = {"flower","flood","flow"};
    cout << commonPrefix(s) << endl;
    return 0;
}