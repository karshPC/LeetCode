#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store numbers and their corresponding indices
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If the complement exists in the map, return the pair of indices
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, store the current number and its index in the map
            numMap[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found (per constraints, a solution always exists)
        return {};
    }
};
