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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto it : mp)
        {
            v.push_back(pair<int, int>(it.first, it.second));
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < k; i++)
        {
            result.push_back(v[i].first);
        }
        return result;
    }
};

// main()
