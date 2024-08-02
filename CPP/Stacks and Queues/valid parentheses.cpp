#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    unordered_map<char, char> bracketMap = {{']', '['}, {')', '('}, {'}', '{'}};
    stack<char> stk;

    for (char bracket : s)
    {
        if (bracketMap.find(bracket) != bracketMap.end())
        {
            if (stk.empty() || stk.top() != bracketMap[bracket])
            {
                return false;
            }
            stk.pop();
        }
        else
        {
            stk.push(bracket);
        }
    }
    return stk.empty();
}

int main()
{
    string s = "()[[]{}";

    bool res = isValid(s);

    cout << res << endl;

    return 0;
}