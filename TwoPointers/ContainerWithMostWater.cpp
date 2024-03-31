

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;

// time complexity O(n)
// Space Complexity O(1)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (right > left)
        {
            int surface = (right - left) * min(height[right], height[left]);
            if (height[right] > height[left])
            {
                left++;
            }
            else
            {
                right--;
            }
            result = max(surface, result);
        }
        return result;
    }
};