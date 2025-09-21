// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array. -->

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        map<int, int> maps;
        int max = INT_MIN;
        int test;

        for(int i=0; i< nums.size(); i++){

            if (maps.find(nums[i]) != maps.end()) {
                maps[nums[i]]++;
            } else {
                maps[nums[i]] = 1;
            }

            if(max < maps[nums[i]]){
                test = nums[i];
                max = maps[nums[i]];
            }

        }

        return test;
    }
};