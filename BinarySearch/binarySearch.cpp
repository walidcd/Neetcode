#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// time complexity O(n)
// Space Complexity O(n)

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int r = nums.size() - 1;
        int l = 0;
        while (r >= l)
        {
            int m = (r + l) / 2;
            if (nums[m] > target)
            {
                r = m - 1;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int arr[] = {-1, 0, 3, 5, 9, 12};
    vector<int> v(arr, arr + 6);
    cout << sol.search(v, 12);
    return 0;
}
