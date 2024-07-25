#include <bits/stdc++.h>

using namespace std;

vector<int> moveZerosOptimal(vector<int> &nums) {
    int k = 0;

    for (int i= 0; i < nums.size(); i++) {
        if (nums[k] == 0 && nums[i] != 0) {
            swap(nums[k], nums[i]);
            k++;
        }
        else if (nums[k] != 0 && nums[i] == 0) {
            k = i; 
        }
    }
    return nums;
}

vector<int> moveZeros(vector<int> &nums)
{
    vector<int> numArr;
    vector<int> zeroArr;

    for (int num : nums)
    {
        if (num != 0)
        {
            numArr.push_back(num);
        }
        else
        {
            zeroArr.push_back(num);
        }
    }
    nums = numArr;
    nums.insert(nums.end(), zeroArr.begin(), zeroArr.end());

    return nums;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    vector<int> result = moveZerosOptimal(nums);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}