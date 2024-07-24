#include <bits/stdc++.h>

using namespace std;

int removeDupliates2(vector<int> &nums)
{
    int k = 1;
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

vector<int> removeDuplicates(vector<int> &nums)
{
    unordered_set<int> num_set;

    vector<int> unique_elements;

    for (int i : nums)
    {
        if (num_set.find(i) == num_set.end())
        {
            unique_elements.push_back(i);
            num_set.insert(i);
        }
    }
    nums = unique_elements;

    return nums;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    vector<int> result = removeDuplicates(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}