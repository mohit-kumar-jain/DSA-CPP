#include <bits/stdc++.h>
using namespace std;

string shortestCompletingWord(string licensePlate, vector<string> &words)
{
    int required[26] = {0};
    for (char ch : licensePlate)
    {
        if (isalpha(ch))
            ++required[tolower(ch) - 'a'];
    }
    string result;
    for (const string &word : words)
    {
        int freq[26] = {0};
        for (char ch : word)
            ++freq[ch - 'a'];

        bool valid = true;
        for (int i = 0; i < 26; ++i)
        {
            if (required[i] > freq[i])
            {
                valid = false;
                break;
            }
        }
        if (valid && (result.empty() || word.length() < result.length()))
            result = word;
    }
    return result;
}

int main()
{
    vector<string> word = {"steps","Stripples", "step","steppel"};
    string licensePlate = "1s3 PSt";
    cout << shortestCompletingWord(licensePlate,word) << endl;
    return 0;
}