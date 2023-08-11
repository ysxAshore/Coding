#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int max=0;
    for (int i = 0; i < s.length(); i++){
        int cur=1;
        string temp=s.substr(i,1);
        for (int j = i+1; j < s.length(); j++){
            if (temp.find_first_of(s[j])!=-1){
                break;
            }else{
                cur++;
                temp=s.substr(i,j-i+1);
            }
        }
        if (max<cur){//最后一个字符的拼接
            max=cur;
        }
    }
    return max;
}
int main(){
    cout<<lengthOfLongestSubstring("jbpnbwwd");
}
