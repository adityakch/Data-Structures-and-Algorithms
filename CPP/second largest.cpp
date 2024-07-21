#include <iostream>
#include <vector>

using namespace std;

int secondLargest2(vector<int> &arr) // single pass
{
    int n = arr.size();
    int largest = arr[0];
    int slargest = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }

    return slargest;
}

int secondLargest(vector<int> &arr) // two pass
{
    int n = arr.size();
    int largest = arr[0];
    int slargest = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > slargest && arr[i] != largest)
        {
            slargest = arr[i];
        }
    }
    return slargest;
}

int main()
{
    vector<int> arr = {1, 5, 3, 9, 2, 8, 4, 7, 6};

    int result = secondLargest2(arr);

    cout << result << endl;

    return 0;
}