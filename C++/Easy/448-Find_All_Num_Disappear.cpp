class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        unordered_map<int,int> unmap;

        // Count each unique value
        for(int j=0; j<nums.size(); j++){
            unmap[nums[j]]++;
        }

        // Search if key exist in map
        vector<int> missNums;
        for(int i=1; i<=nums.size(); i++){
            if(unmap.find(i) == unmap.end()){
                missNums.push_back(i);
            }
        }

        return missNums;
    }
};