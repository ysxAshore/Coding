#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int reverse(int x) {
    stringstream ss;
    ss<<x<<endl;
    string s;
    ss>>s;
    int z;
    if (x<0){
        string temp=s.substr(1,s.size()-1);
        reverse(temp.begin(),temp.end());
        int i=0;
        while (temp[i]=='0'){
            ++i;
        }
        int k=i,j;
        for (j = 1; j <=temp.size()-k; j++) {
           s[j]=temp[i];
           ++i;
        }
        s[j]='\0';
        string temp1;
        ss<<INT32_MIN<<endl;
        ss>>temp1;
        if (s.length()>temp1.length()||(s.length()==temp1.length()&&s>temp1)){
            return 0;
        }
        ss<<s<<endl;
        ss>>z;
    }else{
        reverse(s.begin(),s.end());
        int i=0;
        while (s[i]=='0'&&x!=0){
            ++i;
        }
        string temp=s.substr(i,s.size()-i);
        string temp1;
        ss<<INT32_MAX<<endl;
        ss>>temp1;
        if (temp.length()>temp1.length()||(temp.length()==temp1.length()&&temp>temp1)){
            return 0;
        }
        ss<<temp<<endl;
        ss>>z;
    }
    return z;
}

int main(){
    cout<<reverse(-123);
    return 0;
}

