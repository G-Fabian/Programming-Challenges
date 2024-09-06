/* Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct. */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> unmap;

        // Search nums for duplicate values
        for(int i=0; i < nums.size(); i++){

            // Count each unique element in nums
            unmap[nums[i]]++;

            // Detect duplicate values
            if(test.at(map[i])>1){
                return true;
            }
        }
        // No duplicates found
        return false;
    }
};

