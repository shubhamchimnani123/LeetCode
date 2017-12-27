#incldue <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> record;
        for(int i=0; i<nums.size(); ++i){
            auto found = record.find(target - nums[i]);
            if (found != record.end())
                return {found->second, i};
            else
                record[nums[i]] = i;
        }
        return {-1, -1};
    }
};