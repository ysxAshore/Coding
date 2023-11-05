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

    //有效的字符串须以符号或数字开头
    if (!(isdigit(s[0])||s[0]=='+'||s[0]=='-')){
        return 0;
    }

    //判断符号
    int sign=0;
    i=0;
    if (s[0]=='-'){
        sign=1;
        i=1;
    }else if(s[0]=='+'){
        i=1;
    }else{
        i=0;
    }
    //判断符号之后是不是数字
    if (!isdigit(s[i])){
        return 0;
    }
    //截取有效数字
    int j=i+1;
    while (isdigit(s[j])&&j<s.length()){
        ++j;
    }
    string num=s.substr(i,j-i);
    //去除非0的前0
    int isZero=1;
    for (int k = 0; k < num.length(); k++){
        if (num[k]!='0'&&isdigit(num[k])){
            isZero=0;   
            break;
        }
    }
    if (isZero){
        return 0;
    }else{
        int k;
        for(k=0;k<num.length();++k){
            if (num[k]!='0'){
                break;
            }
        }
        num=num.substr(k,num.length()-k);
    }
    //判断是否越界+转换
    string max,min;
    ss<<INT32_MAX<<endl;
    ss>>max;
    ss<<INT32_MIN<<endl;
    ss>>min;
    int x;
    if (sign){//负数
        string temp=min.substr(1,min.length()-1);
        if (temp.length()<num.length()||(temp.length()==num.length()&&temp<num)){
            return INT32_MIN;//越界
        }
        int k=0,l=1;
        for(;l<=num.length();++l){
            min[l]=num[k];
            ++k;
        }
        min[l]='\0';
        ss<<min<<endl;
        ss>>x;
    }else{
        if (max.length()<num.length()||(max.length()==num.length()&&max<num)){
            return INT32_MAX;//越界
        }
        ss<<num<<endl;
        ss>>x;
    }
    return x;
}
int main(){
    cout<<myAtoi(" -1010023630o4");
    return 0;
}
