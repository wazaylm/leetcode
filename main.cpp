#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution {
public:
//168. Excel Sheet Column Title
    string convertToTitle(int n) {
        string res;
        while(n){
            char t=char((n-1)%26)+'A';
            res=t+res;
            n=(n-1)/26;
        }
        return res;
    }


};


int main() {
    int n;
    cin>>n;
    Solution s;
    cout<<s.convertToTitle(n)<<endl;
    return 0;
}