#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size();

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (target > nums[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;

    int result = binarySearch(nums, target);

    cout << result << endl;
    return 0;
}