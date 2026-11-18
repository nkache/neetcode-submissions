class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<string> arraySet;

        for (int i=0; i<nums.size(); i++)
        {
            if (arraySet.contains(to_string(nums[i]))) return true;

            arraySet.insert(to_string(nums[i]));
        }

        return false;
    }
};