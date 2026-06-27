#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(n + klogk), S.C -> O(k).

static bool comparator(pair<int, char> a, pair<int, char> b)
{
    if (a.first != b.first)
        return a.first > b.first; 
    return a.second < b.second; 
}
string frequencySort(string s)
{
    pair<int, char> freq[128];
    for (int i = 0; i < 128; i++)
        freq[i] = {0, char(i)};
    for (char ch : s)
        freq[(unsigned char)ch].first++;
    sort(freq, freq + 128, comparator);
    string ans;
    for (int i = 0; i < 128; i++)
        ans.append(freq[i].first, freq[i].second);
    return ans;
}

int main()
{
    string s = "aeroplane";
    cout  << frequencySort(s) << endl;
    return 0;
}