#include <bits/stdc++.h>

using namespace std;

vector<int> rotateArray(vector<int> &nums, int k)
{
    int n = nums.size();

    k = k % n;

    // step 1: here we reverse the array
    // step 2: reverse the elements from start to k
    // step 3: reverse the elememts from k to end of arr

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    vector<int> result = rotateArray(nums, k);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}