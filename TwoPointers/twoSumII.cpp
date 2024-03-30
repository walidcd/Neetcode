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
    vector<int> twoSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        while (i <= j)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i + 1, j + 1};
            }
            else if (arr[i] + arr[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return {};
    }
};

// main()