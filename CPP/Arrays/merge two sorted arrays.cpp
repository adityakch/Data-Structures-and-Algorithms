#include <bits/stdc++.h>

using namespace std;

// TC: O(n+m), SC = O(n)
vector<int> mergeArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size(), m = arr2.size();
    int l = 0, r = 0;

    vector<int> res;

    while (l < n && r < m)
    {
        if (arr1[l] <= arr2[r])
        {
            res.push_back(arr1[l]);
            l++;
        }
        else
        {
            res.push_back(arr2[r]);
            r++;
        }
    }

    while (l < n)
    {
        res.push_back(arr1[l]);
        l++;
    }

    while (r < m)
    {
        res.push_back(arr2[r]);
        r++;
    }

    // inplace changes for each array, TC: O(n)
    // for (int i = 0; i<n+m; i++) {
    //     if (i<n) arr1[i] = res[i];
    //     else arr2[i-n] = res[i];
    // }

    arr1.swap(res); // O(1)

    return arr1;
}

// TC: O(m+n), SC: O(1)
// arr1 size must be equal to m+n
vector<int> mergeArrays2(vector<int> &arr1, vector<int> &arr2)
{
    int m = arr1.size(), n = arr2.size();

    int i = m - 1, j = n - 1, k = m + n - 1;

    while (j >= 0)
    {
        if (i >= 0 && arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            i--;
        }
        else
        {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
    return arr1;
}

// gap method (gap = n+m/2 + gap%2 (for ceil val)), then start l=0, r= l + gap
// if r is out of bounds again reduce gap size(gap/2 + gap%2), break if gap == 1
// l and r always moves forword
// TC: [O(logn) * ~(O(n+m))], SC: O(1)
void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int l, int r)
{
    if (arr1[l] > arr2[r])
    {
        swap(arr1[l], arr2[r]);
    }
}

void mergeArrays3(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size(), m = arr2.size();
    int len = n + m;
    int gap = len / 2 + len % 2;

    while (gap > 0)
    {
        int l = 0, r = l + gap;

        while (r < len)
        {
            // l and r in arr1 and arr2
            if (l < n && r >= n)
            {
                swapIfGreater(arr1, arr2, l, r - n);
            }
            // arr2 and arr2
            else if (l >= n)
            {
                swapIfGreater(arr1, arr2, l - n, r - n);
            }
            // arr1 and arr1
            else
            {
                swapIfGreater(arr1, arr2, l, r);
            }
            l++, r++;
        }
        if (gap == 1)
            break;
        gap = gap / 2 + gap % 2;
    }
}

int main()
{
    vector<int> arr1 = {1, 1, 3, 5, 7}, arr2 = {0, 2, 6, 8, 9, 23};

    vector<int> res = mergeArrays2(arr1, arr2);

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}