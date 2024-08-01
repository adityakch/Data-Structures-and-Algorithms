#include <bits/stdc++.h>

using namespace std;

// brute force - O(n^3)
int subArray(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// better - O(n^2)
int subArray2(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// optimal - O(2n)
int subArray3(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0, right = 0;
    int maxLen = 0;
    int sum = arr[0];

    while (right <= n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 10;

    int res = subArray3(arr, k);

    cout << res << endl;

    return 0;
}