#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> num_map;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int diff = target - nums[i];

        if (num_map.find(diff) != num_map.end())
        {
            return {num_map[diff], i};
        }
        num_map[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 3, 4};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty())
    {
        cout << result[0] << "," << result[1] << endl;
    }
    else
    {
        cout << "no pair" << endl;
    }

    return 0;
}