
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int right = nums.size() - 1;
            int left = i + 1;
            while (left < right)
            {
                if (nums[left] + nums[right] == -nums[i])
                {
                    result.push_back({nums[left], nums[right], nums[i]});
                    left++;
                    right--;
                    continue;
                }
                if (nums[left] + nums[right] > -nums[i])
                    right--;
                if (nums[left] + nums[right] < -nums[i])
                    left++;
            }
        }
        set<vector<int>> s(result.begin(), result.end());
        vector<vector<int>> v(s.begin(), s.end());

        return v;
    }
};

// main()