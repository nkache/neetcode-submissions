class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int l = 0, r = heights.size()-1;
        
        while (l < r)
        {
            if (heights[r] < heights[l])
            {
                ans = max(ans, heights[r]*(r-l));
                r--;
            }
            else
            {
                ans = max(ans, heights[l]*(r-l));
                l++;
            }
        }

        return ans;
    }
};
