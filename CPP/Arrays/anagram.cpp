#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool anagram2(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> s_count;
    unordered_map<char, int> t_count;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        s_count[s[i]]++;
        t_count[t[i]]++;
    }

    return s_count == t_count;
}

bool anagram1(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main()
{
    string s = "tab";
    string t = "bat";

    bool result = anagram2(s, t);

    cout << result << endl;

    return 0;
}