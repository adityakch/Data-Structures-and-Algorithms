#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;

    // to find max -> l = mid, r = mid-1
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] > nums[r])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return nums[r];
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};

    int res = binarySearch(nums);

    cout << res << endl;

    return 0;
}