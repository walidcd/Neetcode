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
    int longestConsecutive(vector<int> &nums)
    {
        set<int> s(nums.begin(), nums.end());
        for (auto it : s)
        {
            cout << it << endl;
        }
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();
        int c = 1;
        int prev;
        int result = 0;
        for (auto it : s)
        {
            if (s.count(it + 1))
            {
                c++;
                result = max(c, result);
            }
            else
            {
                c = 1;
                result = max(c, result);
            }
        }
        return result;
    }
};

// main()