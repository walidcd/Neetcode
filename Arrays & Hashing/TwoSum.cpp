#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

// time complexity O(n)
//  Space Complexity O(n)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        // dsa
        unordered_map<int, int> mp;
        // iterate through the input array
        for (int i = 0; i < nums.size(); i++)
        {
            // complement exist
            if (mp.count(target - nums[i]))
            {
                result.push_back(mp[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            // otherwise insert the element with its index
            mp.insert(pair<int, int>(nums[i], i));
        }
        // return the result
        return result;
    }
};

int main()
{
    Solution sol;
    int arr[4] = {2, 7, 11, 15};
    vector<int> nums(arr, arr + 4);
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
