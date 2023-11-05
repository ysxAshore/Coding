#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>temp;
    int j=0,k=0;
    for (; j < nums1.size()&&k<nums2.size();) {
        if(nums1[j]<nums2[k]){
            temp.push_back(nums1[j]);
            ++j;
        }else{
            temp.push_back(nums2[k]);
            ++k;
        }
    }
    if (j<nums1.size()){
        for (int i = j; i < nums1.size(); i++){
            temp.push_back(nums1[i]);
        }
    }
    if (k<nums2.size()){
        for (int i = k; i < nums2.size(); i++){
            temp.push_back(nums2[i]);
        }
    }
    if (temp.size()%2){
        return temp[temp.size()/2];
    }else{
        return (temp[temp.size()/2]+temp[temp.size()/2-1])/2.0;
    }    
    
}

int main(){
    vector<int>A={};
    vector<int>B={1};
    cout<<findMedianSortedArrays(A,B);
}