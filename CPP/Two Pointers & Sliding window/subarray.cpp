#include <bits/stdc++.h>

using namespace std;

// brute force - O(n^3)
vector<vector<int>> subArray(vector<int> &arr)
{
    int n = arr.size();

    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> subarrays;
            for (int k = i; k <= j; k++)
            {
                subarrays.push_back(arr[k]);
            }
            res.push_back(subarrays);
        }
    }
    return res;
}

// better - O(n^2)
vector<vector<int>> subArray2(vector<int> &arr)
{
    int n = arr.size();

    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        vector<int> subarrays;
        for (int j = i; j < n; j++)
        {
            subarrays.push_back(arr[j]);
            res.push_back(subarrays);
        }
        }
    return res;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};

    vector<vector<int>> res = subArray2(arr);

    for (const auto &subarray : res)
    {
        cout << "[ ";
        for (int num : subarray)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}