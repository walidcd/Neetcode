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
    bool containsDuplicate(vector<int> &nums)
    {
        // DS
        unordered_set<int> s;
        // iterate throgh the array O(n)
        for (int i = 0; i < nums.size(); i++)
        {
            // already exists
            if (s.count(nums[i]))
                return true;
            // otherwise
            s.insert(nums[i]);
        }
        // return false
        return false;
    }
};

int main()
{
    Solution sol;
    int arr[4] = {2, 2, 11, 15};
    vector<int> nums(arr, arr + 4);
    bool result = sol.containsDuplicate(nums);
    cout << result;
    // Add more test cases
    return 0;
}