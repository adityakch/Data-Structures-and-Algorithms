#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int target, bool findFirst)
{
    int l = 0;
    int r = nums.size();

    int res = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            res = mid;
            if (findFirst)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else if (target > nums[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}

vector<int> findOccurance(vector<int> &nums, int target)
{
    int firstOccr = binarySearch(nums, target, true);
    int secondOccr = binarySearch(nums, target, false);

    vector<int> res = {firstOccr, secondOccr};

    return res;
}

int countOccurance(vector<int> &nums, int target)
{
    int firstOccr = binarySearch(nums, target, true);
    int secondOccr = binarySearch(nums, target, false);

    if (firstOccr < 0 && secondOccr < 0)
    {
        return 0;
    }
    else
    {
        return secondOccr - firstOccr + 1;
    }
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 8, 8, 10};
    int target = 8;

    // vector<int> res = findOccurance(nums, target);
    int res = countOccurance(nums, target);

    cout << res << endl;

    // for (int num : res)
    // {
    //     cout << num << " ";
    // }

    // cout << endl;

    return 0;
}