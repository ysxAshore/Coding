#include <iostream>
#include <sstream>
using namespace std;

bool isPalindrome(int x) {
    stringstream ss;
    ss<<x;
    string num;
    ss>>num;

    for (int i = 0; i < num.length()/2; i++){
        if (num[i]!=num[num.length()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    cout<<isPalindrome(121);
    return 0;
}
