#include <bits/stdc++.h>

using namespace std;

// brute force, Tc: O(n^2), SC: O(n )
vector<int> nextGreater(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                res[i] = arr[j];
                break;
            }
        }
    }
    return res;
}

// better, TC: O(2n), SC: O(n) + O(n)
vector<int> nextGreater2(vector<int> &arr)
{
    int n = arr.size();
    stack<int> stk;
    vector<int> res(n, -1);

    int r = n - 1;

    while (r >= 0)
    {
        if (stk.empty())
        {
            stk.push(arr[r]);
            r--;
        }
        else if (arr[r] < stk.top())
        {
            res[r] = stk.top();
            stk.push(arr[r]);
            r--;
        }
        else
        {
            stk.pop();
        }
    }
    return res;
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