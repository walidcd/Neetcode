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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> before(n);
        vector<int> after(n);
        before[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            before[i] = before[i - 1] * nums[i - 1];
        }
        after[n - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            after[i] = after[i + 1] * nums[i + 1];
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(before[i] * after[i]);
        }
        return result;
    }
};

// main()