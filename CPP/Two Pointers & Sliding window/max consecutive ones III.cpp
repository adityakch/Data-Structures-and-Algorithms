#include <bits/stdc++.h>

using namespace std;

// brute force, TC: O(n^2), SC: O(1)
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int zeros = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
                zeros++;
            if (zeros <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                zeros = 0;
                break;
            }
        }
    }
    return maxLen;
}

// better, TC: O(2n), SC:O(1)
int longestOnes2(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = 0, zeros = 0;
    int maxLen = 0;

    while (r < n)
    {
        if (nums[r] == 0)
            zeros++;
        while (zeros > k)
        {
            if (nums[l] == 0)
            {
                zeros--;
            }
            l++;
        }

        if (zeros <= k)
            maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

// optimal, TC:O(n), SC:O(1)
int longestOnes3(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = 0, zeros = 0;
    int maxLen = 0;

    while (r < n)
    {
        if (nums[r] == 0)
            zeros++;

        if (zeros > k)
        {
            if (nums[l] == 0)
                zeros--;
            l++;
        }
        else if (zeros <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    int res = longestOnes3(nums, k);

    cout << res << endl;

    return 0;
}