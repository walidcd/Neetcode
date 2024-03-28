#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

// time complexity O(n)
// Space Complexity O(n)

bool isAnagram(string s, string t)
{
    unordered_map<char, int> sm;
    for (int i = 0; i < s.size(); i++)
    {
        sm[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        sm[t[i]]--;
    }
    for (auto it : sm)
    {
        if (it.second != 0)
            return false;
    }
    return true;
}

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> sm;
        for (int i = 0; i < s.size(); i++)
        {
            sm[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            sm[t[i]]--;
        }
        for (auto it : sm)
        {
            if (it.second != 0)
                return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string a = strs[i];
            sort(a.begin(), a.end());
            mp[a].push_back(strs[i]);
        }
        for (auto it : mp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};
// int main()
// {
// }