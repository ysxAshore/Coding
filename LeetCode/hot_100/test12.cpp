#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
string intToRoman(int num) {//num<=3999
    stack<char>roman;
    char src1[4]={'I','X','C','M'};
    char src5[3]={'V','L','D'};
    stringstream ss;
    ss<<num;
    string s;
    ss>>s;
    int j=1;
    for (int i = s.length()-1; i >=0; i--){
        if (s[i]<'4'){
            for (char k = '0'; k < s[i]; k++){
                roman.push(src1[j-1]);
            }
        }else if (s[i]=='4'){
            roman.push(src5[j-1]);
            roman.push(src1[j-1]);
        }else if (s[i]=='9'){
            roman.push(src1[j]);
            roman.push(src1[j-1]);
        }else{
            for (char k = s[i]; k>'5'; k--){
                roman.push(src1[j-1]);
            }
            roman.push(src5[j-1]);
        }
        ++j;
    }
    string res="";
    while (!roman.empty()){
        res.push_back(roman.top());
        roman.pop();
        
    }
    return res;
}   
int main(){
    cout<<intToRoman(1994);
    return 0;
}
