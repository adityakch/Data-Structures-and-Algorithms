#include <bits/stdc++.h>
using namespace std;

int noOfSubseqWithSumK(int idx, vector<vector<int>> &res, vector<int> &subset, vector<int> &arr, int n, int sum, int k) {
    if (idx == n) {
        if (sum == k) {
            return 1;
        }
        return 0;
    }

    sum += arr[idx];
    int left = noOfSubseqWithSumK(idx+1, res, subset, arr, n, sum, k); //pick
    sum -= arr[idx];

    int right = noOfSubseqWithSumK(idx+1, res, subset, arr, n, sum, k); //not pick

    return left + right;

}

bool printAnyOneSubseq(int idx, vector<vector<int>> &res, vector<int> &subset, vector<int> &arr, int n, int sum, int k) {
    if (idx == n) {
        if (sum == k) {
            res.emplace_back(subset);
            return true;
        }
        return false;
    }

    subset.emplace_back(arr[idx]);
    sum += arr[idx];
    if (printAnyOneSubseq(idx+1, res, subset, arr, n, sum, k) == true) return true; //pick
    sum -= arr[idx];
    subset.pop_back();

    if (printAnyOneSubseq(idx+1, res, subset, arr, n, sum, k) == true) return true; //not pick    

    return false;
}

void subseqWithSumK(int idx, vector<vector<int>> &res, vector<int> &subset, vector<int> &arr, int n, int sum, int k) {
    if (idx == n) {
        if (sum == k) {
            res.emplace_back(subset);
        }
        return;
    }

    subset.emplace_back(arr[idx]);
    sum += arr[idx];
    subseqWithSumK(idx+1, res, subset, arr, n, sum, k); //pick
    sum -= arr[idx];
    subset.pop_back();

    subseqWithSumK(idx+1, res, subset, arr, n, sum, k); //not pick    
}

int main() {
    vector<int> arr = {1,2,3,1};
    int k = 3;
    int n = arr.size();
    vector<vector<int>> res;
    vector<int> subset;

    // subseqWithSumK(0, res, subset, arr, n, 0, k);
    printAnyOneSubseq(0, res, subset, arr, n, 0, k);
    int ans = noOfSubseqWithSumK(0, res, subset, arr, n, 0, k);
    cout << ans << endl;

    for (auto subset: res) {
        cout << "[ ";
        for (auto num: subset) {
            cout << num << " ";
        }
        cout << "]";
    }

    return 0;
}