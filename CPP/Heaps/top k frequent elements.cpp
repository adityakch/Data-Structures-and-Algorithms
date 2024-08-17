#include <bits/stdc++.h>
using namespace std;

vector<int> topKElements(vector<int> &arr, int k) {
    unordered_map<int,int> freqMap;
    priority_queue<pair<int,int>> pq;
    vector<int> res;

    for (auto num: arr) {
        freqMap[num]++;
    }

    for (const auto& [key, count]: freqMap) {
        pq.push({count,key});
    }

    for (int i=0; i<k; i++ ) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}

int main() {
    vector<int> arr = {5,-3,9,1,7,7,9,10,2,2,10,10,3,-1,3,7,-9,-1,3,3};
    int k = 3;

    vector<int> res = topKElements(arr, k);

    for (auto i: res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}