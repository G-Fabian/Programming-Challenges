class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        unordered_map<int,int> unmap;

        // Make a map containing all values to n
        for(int i=0; i<=nums.size(); i++){
            unmap[i]=0;
        }

        // Count each unique value
        for(int j=0; j<nums.size(); j++){
            unmap[nums[j]]++;
        }

        // Search for any key with value 0
        for (auto const& x : unmap){
            if(x.second==0){
                return x.first;
            }
        }

        return nums.size();
    }
};