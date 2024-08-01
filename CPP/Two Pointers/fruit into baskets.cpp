#include <bits/stdc++.h>

using namespace std;

// brute force, TC:O(n^2), SC:~O(1)
int totalFruits(vector<int> &arr)
{
    int n = arr.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        set<int> lookup;
        for (int j = i; j < n; j++)
        {
            lookup.insert(arr[j]);
            if (lookup.size() <= 2)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxLen;
}

// better, TC:O(2n); SC: ~O(1)
int totalFruits2(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = 0;
    int maxLen = 0;
    map<int, int> items;

    while (right < n)
    {
        items[arr[right]]++;

        while (items.size() > 2)
        {
            items[arr[left]]--;
            if (items[arr[left]] == 0)
                items.erase(arr[left]);

            left++;
        }

        if (items.size() <= 2)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// optimal, TC:O(n), SC: ~O(1)
int totalFruits3(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = 0;
    int maxLen = 0;
    map<int, int> items;

    while (right < n)
    {
        items[arr[right]]++;

        if (items.size() > 2)
        {
            items[arr[left]]--;
            if (items[arr[left]] == 0)
                items.erase(arr[left]);

            left++;
        }

        else if (items.size() <= 2)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

    int res = totalFruits2(arr);

    cout << res << endl;

    return 0;
}