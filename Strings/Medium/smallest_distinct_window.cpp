#include <bits/stdc++.h>
using namespace std;

int smallString(string s)
{
    int n = s.size(), first = 0, second = 0;
    if (n == 0)
        return 0;
    vector<int> alpha(256, 0);
    int mini = n,diff = 0;
    while (first < n)
    {
        if(alpha[s[first]] == 0)    
            diff++;
        alpha[s[first]]++;
        first++;
    }
    for (int i = 0; i < 256; i++)
    {
        alpha[i] = 0;
    }
    first = 0;

    while(second < n){
        while (diff && second < n)
        {
            if(alpha[s[second]] == 0)
                diff--;

            alpha[s[second]]++;
            second++;
        }
        mini = min(mini,second - first);
        while(diff != 1){
            mini = min(mini,second - first);
            alpha[s[first]]--;

            if(alpha[s[first]] == 0)
                diff++;
            first++;
        }
    }
    return mini;
}

int main()
{
    string s = "abcabdc";
    cout << smallString(s) << endl;
    return 0;
}