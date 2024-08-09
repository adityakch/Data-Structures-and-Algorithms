#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void divide(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    divide(arr, low, mid);
    divide(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

vector<int> mergeSort(vector<int> &arr)
{
    divide(arr, 0, arr.size() - 1);

    return arr;
}

int main()
{
    vector<int> arr = {9, 2, 4, 6, 8, 2, 1, 3, 7};

    vector<int> res = mergeSort(arr);

    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}