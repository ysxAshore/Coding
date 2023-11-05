#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//O(n^2)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>temp;
    for (size_t i = 0; i < nums.size(); i++){
        bool success=false;
        for (size_t j = i+1; j < nums.size(); j++){
            if (nums[i]+nums[j]==target){
                temp.push_back(i);
                temp.push_back(j);
                bool success=true;
                break;
            }
        }
        if (success){
            break;
        }
    }
    return temp;
}

//小于O(n^2)
vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int>temp,_nums;
    map<int,int>isExit;
    for (size_t i = 0; i < nums.size(); i++){
        isExit.insert(make_pair(nums[i],i));
    }
    
    for (size_t i = nums.size()-1; i >=0; i--){
        if (isExit.find(target-nums[i])!=isExit.end()&&isExit[target-nums[i]]!=i){
            temp.push_back(i);
            temp.push_back(isExit[target-nums[i]]);
            break;
        }
    }
    return temp;
}
int main(){
    vector<int>nums={2,4,11,3};
    int target=6;
    vector<int>temp=twoSum2(nums,target);
    cout<<temp[0]<<" "<<temp[1];
}