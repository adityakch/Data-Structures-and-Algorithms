#include <bits/stdc++.h>

using namespace std;

// TC: O(n) * O(k)
vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> res;

    for (int i = k; i <= n; i++)
    {
        res.push_back(*max_element(arr.begin() + (i - k), arr.begin() + i));
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> res = maxSlidingWindow(arr, k);

    cout << "[ ";
    for (auto i : res)
    {
        cout << i << " ";
    }

    cout << "]" << endl;

    return 0;
}