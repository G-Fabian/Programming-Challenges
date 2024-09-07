/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
         
        // Using the XOR operator the only digit remaining will
        // be the single digit. ** This works since the problem requires
        // only one digit if it was >1 then this would not work

        // 0 ^ A = A
        // A ^ A = 0
        // A ^ A ^ B = B

        int x = 0;
        for(auto i : nums){
            x = x^i;
        }

        return x;
    }
};

