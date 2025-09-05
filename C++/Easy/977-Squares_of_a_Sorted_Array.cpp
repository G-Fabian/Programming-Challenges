class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        

        // *** Solved with multiset *** 
        multiset<int> solution;
        
        // While traversing the array square element and insert to set
        for(int i=0; i<nums.size(); i++){
            solution.insert(nums[i]*nums[i]);
        }

        // Transfer data from multiset solution to vector v
        vector<int> v(solution.begin(), solution.end());
        return v;
    }
};


// [-4,-1,0,3,10]

// 4=16 < 10=100  [0,0,0,0,100]
// 4=16 > 3=9     [0,0,0,16,100]
// 1=1 < 3=9      [0,0,9,16,100]
// 1=1 > 0=0      [0,1,9,16,100]
// 0=0            [0,1,9,16,100]
