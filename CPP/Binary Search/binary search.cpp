
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right-left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        else if (target > arr[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1,3,4,5,7,9,10};
    int target = 7;

    int result = binarySearch(arr, target);

    cout << result << endl;
    return 0;
}