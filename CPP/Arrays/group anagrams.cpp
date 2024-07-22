#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams1(vector<string> &strs)
{
    unordered_map<string, vector<string>> anagramDict;

    for (const string &word : strs)
    {
        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());

        anagramDict[sorted_word].push_back(word);
    }

    vector<vector<string>> result;
    for (const auto &pair : anagramDict)
    {
        result.push_back(pair.second);
    }

    return result;
}

void printResult(const vector<vector<string>> &result)
{
    cout << "[";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << '"' << result[i][j] << '"';
            if (j < result[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

int main()
{
    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};

    vector<vector<string>> result = groupAnagrams1(strs);

    printResult(result);

    return 0;
}