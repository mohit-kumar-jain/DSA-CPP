#include<bits/stdc++.h>
using namespace std;
                              
int main() {
    string s = "HEllo World.";
    cout << "Given word : " << s << endl;
    for(char& c : s){
        c = tolower(c);
    }
    cout << "Given word in Lower Case : " << s << endl;
    for(char& c : s){
        c = toupper(c);
    }
    cout << "Given word in Upper Case : " << s << endl;
    return 0;
}