// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;

        vector<int> solution;
        while(left<nums.size() && right>0){

            int sum = nums[left] + nums[right];

            sum = abs(sum);
            target = abs(target);
            if(sum == target){
                solution.push_back(left);
                solution.push_back(right);
                return solution;
            }

            if(sum < target)
                left++;
            
            if(sum > target)
                right--;
        }

        return nums;
    }
};


// [-1,-2,-3,-4,-5]
// target = -8
// -1 -5 = -6
// -2 -5 = -7