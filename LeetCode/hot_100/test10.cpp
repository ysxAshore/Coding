#include <iostream>

using namespace std;
bool sub_process(string &s,int i,string &p,int j){
    if (p[j]==0){
        return s[i]==0;
    }
    auto match=s[i]&&(s[i]==p[j]||p[j]=='.');
    if(p[j+1]=='*'){
        return sub_process(s,i,p,j+2)||(match&&sub_process(s,i+1,p,j));
    }else{
        return match&&sub_process(s,i+1,p,j+1);
    }
}
bool isMatch(string s, string p) {
    return sub_process(s,0,p,0);
}   
int main(){
    cout<<isMatch("aa","a*");
    return 0;
}
