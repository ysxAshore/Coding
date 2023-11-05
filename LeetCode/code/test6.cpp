#include <iostream>
#include <string>
using namespace std;
char res[1000][1000]={{0}};
string convert(string s, int numRows) {
    string temp=s;
    if (numRows!=1){
        int one_size=2*numRows-2,one_cow=numRows-1;
        int group=s.size()%one_size==0?s.size()/one_size:s.size()/one_size+1;
        int row=numRows,col=group*one_cow;
        int i=1;
        while (i<=s.size()){
            int cycle=(i-1)/one_size;
            for (int j = 0; j < numRows&&i<=s.size(); j++) {
                res[j][cycle*one_cow]=s[i-1];
                ++i;
            }
            for (int j = numRows-2; j >=1&&i<=s.size(); j--) {
                res[j][(i-(cycle*one_size)-numRows)+cycle*one_cow]=s[i-1];
                ++i;
            }
        }
        i=1;
        for (int j = 0; j < numRows; j++) {
            for (int k = 0; k < col; k++){
                if (res[j][k]!=0){
                    temp[i-1]=res[j][k];
                    ++i;
                    if (i>s.size()){
                        break;
                    }
                }
            }
            if (i>s.size()){
                    break;
            }
        }
    }
    return temp;
}
int main(){
    cout<<convert("A",1);
}