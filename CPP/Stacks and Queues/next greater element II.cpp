#include <bits/stdc++.h>

using namespace std;

// brute force, TC: O(n^2), SC: O(n)
vector<int> nextGreater(vector<int> &arr)
{
    int n = arr.size();

    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < i + n; j++)
        {
            int idx = j % n;
            if (arr[idx] > arr[i])
            {
                ans[i] = arr[idx];
                break;
            }
        }
    }
    return ans;
}

// better,
vector<int> nextGreater2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> stk;

    int r = 2 * n - 1;

    while (r >= 0)
    {
        if (stk.empty())
        {
            stk.push(arr[r % n]);
            r--;
        }
        else if (arr[r % n] < stk.top())
        {
            ans[r % n] = stk.top();
            stk.push(arr[r % n]);
            r--;
        }
        else
        {
            stk.pop();
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};

    vector<int> res = nextGreater2(arr);

    cout << "[ ";
    for (auto i : res)
    {
        cout << i << " ";
    }

    cout << "]" << endl;

    return 0;
}