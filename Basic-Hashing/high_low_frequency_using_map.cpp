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
    int maxFreq = 0, minFreq = s.size();
    int maxEle = 0, minEle = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (auto it : mapp) {

            int element = it.first;
            int count = it.second;

            if (count > maxFreq) {
                maxFreq = count;
                maxEle = element;
            }

            if (count < minFreq) {
                minFreq = count;
                minEle = element;
            }
        }
    }
    cout << "The highest frequency element is: " << char(maxEle) << "\n";
    cout << "The lowest frequency element is: " <<char(minEle) << "\n";
    // int n;
    // cin>>n;
    // while(n--){
    //     char c;
    //     cin>>c;
    //     cout<<mapp[c]<<endl;
    // }
    return 0;
}