#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
        {
            count++;
        }

        if (count > 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 6, 2};

    bool result = check(nums);

    cout << result << endl;

    return 0;
}