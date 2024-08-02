#include <bits/stdc++.h>

using namespace std;

// brute force
vector<int> prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                res[j] = arr[i];
                break;
            }
        }
    }
    return res;
}

// better, TC: O(2n), SC:O(2n)
vector<int> prevSmaller2(vector<int> &arr)
{
    int n = arr.size();
    stack<int> stk;
    vector<int> res(n, -1);

    int r = 0;

    while (r < n)
    {
        if (stk.empty())
        {
            stk.push(arr[r]);
            r++;
        }
        else if (arr[r] > stk.top())
        {
            res[r] = stk.top();
            stk.push(arr[r]);
            r++;
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
    vector<int> arr = {34, 35, 27, 42, 5, 28, 39, 20, 28};

    vector<int> res = prevSmaller(arr);

    cout << "[ ";
    for (auto i : res)
    {
        cout << i << " ";
    }

    cout << "]" << endl;

    return 0;
}