#include <iostream>

using namespace std;
int romanToInt(string s) {
    int res=0;
    for (int i = 0; i <s.length(); i++){
        if (s[i]=='M'){
            res+=1000;
        }else if (s[i]=='D'){
            res+=500;
        }else if (s[i]=='C'){
            int j=i+1;
            if (j<s.length()&&s[j]=='D'){
                res+=400;
                i=j;
            }else if (j<s.length()&&s[j]=='M'){
                res+=900;
                i=j;
            }else{
                res+=100;
            }
        }else if (s[i]=='L'){
            res+=50;
        }else if (s[i]=='X'){
            int j=i+1;
            if (j<s.length()&&s[j]=='L'){
                res+=40;
                i=j;
            }else if (j<s.length()&&s[j]=='C'){
                res+=90;
                i=j;
            }else{
                res+=10;
            }
        }else if (s[i]=='V'){
            res+=5;
        }else if (s[i]=='I'){
            int j=i+1;
            if (j<s.length()&&s[j]=='V'){
                res+=4;
                i=j;
            }else if (j<s.length()&&s[j]=='X'){
                res+=9;
                i=j;
            }else{
                res+=1;
            }
        } 
    }
    return res;
}
int main(){
    cout<<romanToInt("LVIII");
    return 0;
}
