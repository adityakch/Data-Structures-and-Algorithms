#include <iostream>
#include <vector>

using namespace std;

int largestElement(vector<int> &arr, int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    vector<int> arr = {1, 5, 3, 9, 2, 8, 4, 7, 6}; // Use vector instead of array
    int n = arr.size();
    int result = largestElement(arr, n); // Pass arguments and capture return value

    // Print the result
    cout << result << endl;

    return 0;
}
