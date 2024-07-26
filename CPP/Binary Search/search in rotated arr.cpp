#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[l] <= nums[mid])
        { // left part sorted
            if (nums[l] <= target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target <= nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 2;

    int res = binarySearch(nums, target);

    cout << res << endl;

    return 0;
}