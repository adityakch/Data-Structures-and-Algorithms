#include <bits/stdc++.h>

using namespace std;

void generateSubsequence(int idx, vector<vector<int>>& res, vector<int> &subset, vector<int> &arr, int n) {
    if (idx == n) {
        res.emplace_back(subset);

        return;
    }

    subset.emplace_back(arr[idx]);
    generateSubsequence(idx+1, res, subset, arr, n); //pick
    subset.pop_back();

    generateSubsequence(idx+1, res, subset, arr, n); //not pick
}

int main() {
    vector<int> arr = {3,1,2,4};
    int n = arr.size();

    vector<vector<int>> res;
    vector<int> subset;
    
    generateSubsequence(0, res, subset, arr, n);

    for (auto subset: res) {
        cout << "[ ";
        for (auto num: subset) {
            cout << num << " ";
        }
        cout << "]";
    }

    return 0;
}