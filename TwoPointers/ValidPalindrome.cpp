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
    bool isPalindrome(string s)
    {
        string t;
        for (int i = 0; i < s.size(); i++)
        {
            if (!isalnum(s[i]))
                continue;
            t.push_back(s[i]);
        }
        int left = 0;
        int right = t.size() - 1;
        while (right >= left)
        {
            if (t[left])
                if (tolower(t[right]) != tolower(t[left]))
                    return false;
            right--;
            left++;
        }
        return true;
    }
};

// main()