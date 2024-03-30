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
// Space Complexity O(n)

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int trapped = 0;
        int left = 0;
        int right = height.size() - 1;
        int Maxleft = 0;
        int Maxright = 0;
        while (left < right)
        {
            if (height[left] > height[right] && Maxright > height[right])
            {
                trapped += Maxright - height[right];
                right--;
            }
            else if (height[left] > height[right] && Maxright <= height[right])
            {
                Maxright = height[right];
                right--;
            }
            else if (height[right] >= height[left] && Maxleft > height[left])
            {
                trapped += Maxleft - height[left];
                left++;
            }
            else if (height[right] >= height[left] && Maxleft <= height[left])
            {
                Maxleft = height[left];
                left++;
            }
        }
        return trapped;
    }
};