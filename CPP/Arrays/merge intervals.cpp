#include <bits/stdc++.h>

using namespace std;

// better, TC: O(nlogn) + O(2n), SC: O(n)
vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end()); // O(nlogn)

    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!ans.empty() && start <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// optimal, TC: O(nlogn) + O(n), SC: O(n)
vector<vector<int>> mergeIntervals2(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        if (ans.empty() || start > ans.back()[1])
        {
            ans.push_back({start, end});
        }
        else if (!arr.empty() && start <= ans.back()[1])
        {
            end = max(ans.back()[1], end);
            ans.back()[1] = end;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {6, 7}, {2, 6}, {8, 10}, {9, 11}, {15, 18}};

    vector<vector<int>> res = mergeIntervals(intervals);

    cout << "[ ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
        if (i < res.size() - 1)
            cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}