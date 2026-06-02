#include<bits/stdc++.h>
                   
using namespace std;
                   
int main() {
    string s;
    cin>>s;
    int hashh[25] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hashh[s[i]-'a'] += 1;
    }
    int n;
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        cout<<hashh[c-'a']<<endl;
    }
    return 0;
}