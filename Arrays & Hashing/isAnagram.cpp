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

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // a first approach

        /*
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
        */

        // second approach

        // DS Map
        unordered_map<char, int> sm;
        unordered_map<char, int> tm;
        // edge case;
        if (s.size() != t.size())
            return false;
        // iterate and count each char occurence
        for (int i = 0; i < s.size(); i++)
        {
            sm[s[i]]++;
            tm[t[i]]++;
        }
        // iterate through two maps and check for key value equality
        for (auto it : sm)
        {
            if (tm[it.first] != sm[it.first])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "anagram", t = "nagaram";
    bool result = sol.isAnagram(s, t);
    cout << result;
    // Add more test cases
    return 0;
}