#include<bits/stdc++.h>
using namespace std;
      
// T.C -> O(mlog m + nlog n + m) , S.C -> O(1).
int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
    int n = Student.size(), m = Cookie.size();
    sort(Student.begin(),Student.end());
    sort(Cookie.begin(),Cookie.end());
    int l = 0, r = 0;
    while(l < n && r < m) {
        if(Student[l] <= Cookie[r]){
            r++;
        }
        l++;
    }
    return r;
}                   
                   
int main() {
    vector<int> student = {1,2,3};
    vector<int> cookie = {1,1};
    cout << findMaximumCookieStudents(student, cookie);
    return 0;
}