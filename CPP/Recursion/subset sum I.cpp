#include <bits/stdc++.h>
using namespace std;

void subsetSum(int idx, vector<int> &res, vector<int> &arr, int sum) {
    if (idx == arr.size()) {
        res.push_back(sum);
        return;
    }

    sum += arr[idx];
    subsetSum(idx+1, res, arr, sum); // pick
    sum -= arr[idx];

    subsetSum(idx+1, res, arr, sum); // not pick
}

int main() {
    vector<int> arr = {2,3};
    vector<int> res;

    subsetSum(0, res, arr, 0);

    for (auto num: res) {
        cout << num << " ";
    }

    return 0;
}