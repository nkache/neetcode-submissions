class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> numset(nums.begin(), nums.end());

        for (int num: nums)
        {
            if (!numset.count(num) || numset.count(num-1)) continue;
            
            int length = 1;
            while (numset.count(num+length)) length++;
            ans = max(ans, length);
        }

        return ans;
    }
};
