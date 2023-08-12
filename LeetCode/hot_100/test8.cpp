#include <iostream>
#include <sstream>
using namespace std;
int myAtoi(string s) {
    stringstream ss;
    //去掉前导空格
    int i=0;
    while (s[i]==' '){
        ++i;
    }
    s=s.substr(i,s.size()-i);
    
    //检测第一个数字
    i=0;
    while (!isdigit(s[i])){
        ++i;
    }
    //检测最后一个数字
    int j=i+1;
    while (isdigit(s[j])){
        ++j;
    }
    string res=s.substr(i,j-i);
    if (s[i-1]=='-'){
        string temp=s;
        temp[0]='-';
        int l=1;
        for (int k = 0; k < res.length(); k++){
            temp[l]=res[k];
            ++l;
        }
        temp[l]='\0';
        string min_num;
        ss<<INT32_MIN;
        ss>>min_num;
        if (temp.length()>min_num.length()||(temp.length()==min_num.length()&&temp>min_num)){
            res=min_num;
        }else{
            res=temp;
        }
    }else{
        string max_num;
        ss<<INT32_MAX;
        ss>>max_num;
        if (res.length()>max_num.length()||(res.length()==max_num.length()&&res>max_num)){
            res=max_num;
        }
    }
    stringstream s_(res);
    int a;
    s_>>a;
    return a;
}
int main(){
    cout<<myAtoi("123456789452");
    return 0;
}
