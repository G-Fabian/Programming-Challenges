// Given an array of integers nums which is sorted in ascending order, and an integer target, 
// write a function to search target in nums. If target exists, then return its index. 
// Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.


class Solution {
public:
    int search(vector<int>& nums, int target) {

        int mid;
        int low = 0;
        int high = nums.size() - 1; 

        while(low<=high){
            // Calculate the index of middle element
            mid = (high + low) / 2;

            // Case 1: Target is found
            if(nums[mid]==target){
                return mid;
            }
            // Case 2: Target is smaller than the middle value
            // Update high to ignore all elements after the middle index
            else if(nums[mid]>target){
                high = mid - 1;
            }
            // Case 2: Target is greater than the middle value
            // Update low to ignore all elements before the middle index
            else if(nums[mid]<target){
                low = mid + 1;
            }

        }
        // Target was not found in array
        return -1;
    }
};