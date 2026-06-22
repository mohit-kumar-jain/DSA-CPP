#include<bits/stdc++.h>         
using namespace std;

// Optimal. T.C. -> O(n), S.C. -> O(no.of.vowels).
string sortVowels(string& s){
    string res;
    vector<int> lower(26,0); 
    vector<int> upper(26,0); 
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a'||s[i] == 'e'||s[i] == 'o'||s[i] == 'u'||s[i] == 'i'){
            lower[s[i] - 'a']++;
            s[i] = '$';
        }
        else if(s[i] == 'A'||s[i] == 'E'||s[i] == 'I'||s[i] == 'O'||s[i] == 'U'){
            upper[s[i] - 'A']++;
            s[i] = '$';
        }
    }
    for (int i = 0; i < 26; i++)
    {
        while(upper[i]){
            res += 'A' + i;
            upper[i]--;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        while(lower[i]){
            res += 'a' + i;
            lower[i]--;
        }
    }
    int first = 0, second  = 0;
    while(first < s.size() && second < res.size()){
        if(s[first] == '$'){
            s[first] = res[second];
            second++;
        }
        first++;
    }
    
    return s;
}

int main() {
    string s = "lEetcOde";
    string res = sortVowels(s);
    cout << res << endl;
    return 0;
}