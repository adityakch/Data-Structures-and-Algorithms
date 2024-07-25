#include <bits/stdc++.h>

using namespace std;

// to find majority element of > n/2, we can do it by three approaches
// 1. sort and return n/2 element in arr -> O(nlogn)
// 2. store num count in dict and run for loop to check if key's value > n/2 if found return key
// 3. moore's algo initialise count = 0, iterate through arr, take candidate as 1st element increase count if num = candidate else decrease

// approach 1, O(nlogn)
int majorityElement1(vector<int> &nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int res = nums[n / 2];

    return res;
}

// approach 2, O(x + n)
int majorityElement2(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> num_count;

    for (int num : nums)
    {
        num_count[num]++;
    }

    for (auto pair : num_count)
    {
        if (pair.second > n / 2)
        {
            return pair.first;
        }
    }
    return 0;
}

// approach 3, O(n)

int majorityElement3(vector<int> &nums)
{
    int count = 0;
    int candidate = 0;

    for (int num : nums)
    {

        if (count == 0)
        {
            candidate = num;
        }

        if (candidate == num)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = majorityElement3(nums);

    cout << result << endl;

    return 0;
}