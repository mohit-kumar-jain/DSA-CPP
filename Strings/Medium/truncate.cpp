#include <bits/stdc++.h>
using namespace std;

string truncateSentence(string s, int k)
{
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == ' ' && --k == 0)
            return s.substr(0, i);
    return s;
}

int main()
{
    string s = "Hello how are you. I am fine wbu";
    int k = 5;
    cout << truncateSentence(s, k) << endl;
    return 0;
}