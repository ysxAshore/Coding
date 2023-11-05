#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int min = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            int cur = nums[i] + nums[j] + nums[k];
            if (abs(cur - target) < abs(min - target))
            {
                min = cur;
            }
            if (cur > target)
            {
                k--;
            }
            else if (cur < target)
            {
                j++;
            }
            else
            {
                return target;
            }
        }
    }
    return min;
}
int main()
{
    vector<int> S = {0, 0, 0};
    cout << threeSumClosest(S, 1);
    return 0;
}
