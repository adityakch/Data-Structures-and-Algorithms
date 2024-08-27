#include <bits/stdc++.h>
using namespace std;

//TC: O(2n), SC:O(n)
vector<int> asteroidCollision(vector<int> &arr) {
    vector<int> stk;

    for (int num: arr) { // O(n)
        if (num > 0) {
            stk.push_back(num);
        }
        else {
            while (!stk.empty() && stk.back() > 0 && stk.back() < abs(num)) //O(n)
            {
                stk.pop_back();
            }
            if (!stk.empty() && stk.back() == abs(num)) {
                stk.pop_back();
            }
            else if (stk.empty() || stk.back() < 0) {
                stk.push_back(num);
            }
            
        }
    }
    return stk;
}

int main() {
    vector<int> arr = {46, -36, 3, 39, 20, -33, 35, 4, -26, -37, 27, -50, -23, 48, 5, 
    -1, 29, -34, 34, 11, 22, 8, 41, -20, -10, 17, 35, -14, -9, 3, 12, -13, -47, 23, -39, 
    25, -43, -2, 26, -26, -42, -5, -4, 34, 3, 25, 20, 27, -6};

    vector<int> res = asteroidCollision(arr);

    for (auto num: res) {
        cout << num << " ";
    }

    return 0;
}