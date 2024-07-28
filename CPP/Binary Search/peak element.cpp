#include <bits/stdc++.h>

using namespace std;

int bruteForce(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> &nums)
{
    int n = nums.size();
    int l = 1;
    int r = n - 2;

    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid] > nums[mid - 1])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 7, 5, 6, 4};

    // int res = binarySearch(nums);
    int res = bruteForce(nums);

    cout << res << endl;

    return 0;
}