#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    string s="";
    sort(strs.begin(),strs.end());
    string temp="";
    int j=0;
    while (j<strs[0].length()){
        temp.push_back(strs[0][j]);
        bool sign=true;
        for (int i = 1; i < strs.size(); i++){
            string t=strs[i].substr(0,j+1);
            if (t!=temp){
                sign=false;
                break;
            }
        }
        if (sign){
            ++j;
            s=temp;
        }else{
            break;
        }
    }
    return s;
}
int main(){
    vector<string>s={"dog","racecar","car"};
    cout<<longestCommonPrefix(s);
    return 0;
}
