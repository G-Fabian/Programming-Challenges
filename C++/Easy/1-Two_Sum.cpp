// Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target. You may assume that each input
// would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

class Solution {
public:

    // Traverse the array in a single pass. For each number, compute the 
    // difference between the target and the number. If the difference is 
    // already in the map, we found a match. Otherwise, store the number 
    // and its index in the map for future checks.
    vector<int> twoSum(vector<int>& nums, int target) {
       
        map<int, int> solution; // Store number and index

        for (int i = 0; i < nums.size(); i++) {

            // Calculate difference
            int difference = target - nums[i];

            // Search if difference is in map
            auto it = solution.find(difference);
            if (it != solution.end()) {
                return {it->second, i};
            }
            // Save current number and index
            solution.insert({nums[i], i});
        }
        // Solution not found
        return {0, 0};
    }
};