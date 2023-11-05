#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int> height) {
    int max=(height.size()-1)*(min(height[0],height[height.size()-1]));
    int i=0,j=height.size()-1;
    while (i<j){
        int temp=(j-i)*min(height[i],height[j]);
        if (max<temp){
            max=temp;
        }
        if (height[i]<height[j]){
            ++i;//当前的面积计算取得是height[i]，那么如果i不变，右边变的话，底在减小，无论如何所得面积不会更大
        }else{
            --j;//同i的思想
        }
    }
    
    return max;
}
int main(){
    cout<<maxArea({1,8,6,2,5,4,8,3,7});
    return 0;
}
