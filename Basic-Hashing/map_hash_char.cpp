#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    map<char ,int>mapp;
    for (int i = 0; i < s.size(); i++)
    {
        mapp[s[i]] += 1;
    }
    int n;
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        cout<<mapp[c]<<endl;
    }
    return 0;
}