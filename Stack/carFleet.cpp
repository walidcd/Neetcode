#define INF 1e8
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

int findMeetingPoint(int speed1, int position1, int speed2, int position2)
{
    int d1 = position1;
    int d2 = position2;
    while (d1 != d2)
    {
        if (d1 < d2)
        {
            d1 += speed1;
        }
        else
        {
            d2 += speed2;
        }
    }
    return d1;
}

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        stack<float> st;
        for (int i = 0; i < v.size(); i++)
        {
            float time = ((float)(target - v[i].first)) / ((float)v[i].second);
            while (!st.empty() && time >= st.top())
            {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};