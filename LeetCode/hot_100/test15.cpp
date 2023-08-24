#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());//升序
    for (int i = 0; i < nums.size()-2; i++){
        int j=i+1,k=nums.size()-1;
        while (j<k){
            while (j<k&&nums[i]+nums[j]+nums[k]<0){
                ++j;
            }
            while (j<k&&nums[i]+nums[j]+nums[k]>0){
                --k;
            }
            if (nums[i]+nums[j]+nums[k]==0){
                ans.push_back({nums[i],nums[j],nums[k]});
                while(j<k){
                    ++j;
                    if (nums[j]!=nums[j-1]){
                        break;
                    }
                }
                while(j<k){
                    --k;
                    if(nums[k]!=nums[k+1]){
                        break;
                    }
                }
            }
        }
        while(i<nums.size()-2 && nums[i+1]==nums[i]) i++;
    }
    return ans;
}
int main(){
    
    return 0;
}
